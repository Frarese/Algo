#include<iostream>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/push_relabel_max_flow.hpp>
#include<vector>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor>>>> Graph;
typedef traits::vertex_descriptor Vertex;
typedef traits::edge_descriptor Edge;
typedef std::vector<int> Vi;

class Edge_adder {
  Graph &G;

 public:
  explicit Edge_adder(Graph &G) : G(G) {}

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
  int n,m,s,d; std::cin >> n >> m >> s >> d;
  Graph G(2*n);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  Edge_adder adder(G);

  for(int i = 0; i< n; i++)
    adder.add_edge(2*i,2*i+1,1);

  for (size_t i = 0; i < m; i++) {
    int u,v; std::cin >> u >> v;
    adder.add_edge(2*u+1,2*v,1);
  }

  for (size_t i = 0; i < s; i++) {
    int u; std::cin >> u;
    adder.add_edge(source, 2*u,1);
  }

  for (size_t i = 0; i < d; i++) {
    int u; std::cin >> u;
    adder.add_edge(2*u+1, sink,1);
  }

  int max_flow = boost::push_relabel_max_flow(G, source, sink);

  std::cout << max_flow << "\n";

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
