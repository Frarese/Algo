#include <iostream>
#include <cmath>
// BGL include
#include <boost/graph/adjacency_list.hpp>

// BGL flow include *NEW*
#include <boost/graph/push_relabel_max_flow.hpp>

// Graph Type with nested interior edge properties for flow algorithms
typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> graph;

typedef traits::vertex_descriptor vertex_desc;
typedef traits::edge_descriptor edge_desc;
typedef boost::graph_traits<graph>::edge_iterator   edge_it;



// Custom edge adder class, highly recommended
class edge_adder {
  graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}

  void add_edge(int from, int to, long capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    const auto e = boost::add_edge(from, to, G).first;
    const auto rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }
};

void solve()
{
  int n,m,k,l; std::cin >> n >> m >> k >> l;
  graph G(2*n+2);
  int source = 2*n;
  int sink = 2*n+1;
  edge_adder adder1(G);

  for (size_t i = 0; i < k; i++) {
    int x; std::cin >> x;
    adder1.add_edge(source, 2*x, 1);
    adder1.add_edge(2*x+1, sink, 1);

  }
  for (size_t i = 0; i < l; i++) {
    int x; std::cin >> x;
    adder1.add_edge(2*x, 2*x+1, 1);
  }
  for (size_t i = 0; i < m; i++) {
    int x,y; std::cin >> x >> y;
    adder1.add_edge(2*x, 2*y, 500);
    adder1.add_edge(2*x+1, 2*y+1, 1);
  }

  long flow1 = boost::push_relabel_max_flow(G, source, sink);

  std::cout << flow1 << "\n";
  //std::cout << std::min(flow1,flow2) << "\n";

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
