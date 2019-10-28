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

// Custom edge adder class, highly recommended
class edge_adder {
  Graph &G;

 public:
  explicit edge_adder(Graph &G) : G(G) {}

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

void shopping()
{
  int n,m,s; std::cin >> n >> m >> s;
  Graph G(n);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  edge_adder adder(G);
  Vi stores(n,0);
  for(int i = 0; i< s; i++)
  {
    int l; std::cin >> l;
    stores[l]++;
  }
  for(int i = 0; i< m; i++)
  {
        int u,v; std::cin >> u >> v;
        adder.add_edge(u,v,1);
        adder.add_edge(v,u,1);
  }

  adder.add_edge(source, 0, s);
  for(int i = 0; i< n; i++)
    adder.add_edge(i,sink, stores[i]);

    int max_flow = boost::push_relabel_max_flow(G, source,sink);
    if(s == max_flow)
      std::cout << "yes\n";
    else
    std::cout << "no\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(int i = 0; i< T; i++)
    shopping();
  return 0;
}
