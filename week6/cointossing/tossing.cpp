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

void tossing()
{
  int n,m; std::cin >> n >> m;
  Vi showed(n),current(n,0);
  Graph G(n+m);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  Edge_adder adder(G);

  int missing = 0;
  for(int i = 0; i< m; i++)
  {
    int a,b,c; std::cin >> a >> b >> c;
    if(c == 1)
      current[a] += 1;
    else if(c == 2)
      current[b] += 1;
    else
    {
      missing++;
      adder.add_edge(n+i, a, 1);
      adder.add_edge(n+i, b, 1);
      adder.add_edge(source, n+i, 1);
    }
  }

  bool fake = false;
  for(int i = 0; i< n; i++)
  {
    std::cin >> showed[i];
    if(showed[i] < current[i])
      fake = true;
  }

  int total = 0;
  if(!fake)
  {
    for(int i = 0; i< n; i++)
    {
      int c = showed[i]-current[i];
      adder.add_edge(i, sink, c);
      total += c;
    }

    int max_flow = boost::push_relabel_max_flow(G, source, sink);
    if(max_flow == total && total == missing)
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }
  else
    std::cout<< "no\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(int i = 0; i< T; i++)
    tossing();
  return 0;
}
