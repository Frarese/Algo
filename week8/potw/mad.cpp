#include <iostream>

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

void mad() {
  int Z,J; std::cin >> Z >> J;
  graph G(Z+J);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  edge_adder adder(G);

  for (size_t i = 0; i < Z; i++) {
    int c; std::cin >> c;
    adder.add_edge(source, i, c);
  }
  long total = 0;
  for (size_t i = 0; i < J; i++) {
    int p; std::cin >> p;
    total+= p;
    adder.add_edge(Z+i, sink, p);
  }
  for (size_t i = 0; i < J; i++) {
    int n; std::cin >> n;
    for (size_t j = 0; j < n; j++) {
      int z; std::cin >> z;
      adder.add_edge(z,Z+i,5000);
    }
  }
  long flow = boost::push_relabel_max_flow(G, source, sink);

  std::cout << total - flow << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  while (T--) {
    mad();
  }
}
