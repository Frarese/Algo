#include<iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, int,
        boost::property<boost::edge_residual_capacity_t, int,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                boost::property <boost::edge_weight_t, int> > > > > graph; // new! weightmap corresponds to costs

typedef boost::graph_traits<graph>::edge_descriptor             edge_desc;
typedef boost::graph_traits<graph>::out_edge_iterator           out_edge_it;

class edge_adder {
 graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}
  void add_edge(int from, int to, long capacity, long cost) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    auto w_map = boost::get(boost::edge_weight, G); // new!
    const edge_desc e = boost::add_edge(from, to, G).first;
    const edge_desc rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
    w_map[e] = cost;   // new assign cost
    w_map[rev_e] = -cost;   // new negative cost
  }
};

void solve()
{
  int n,m; std::cin>> n >> m;
  graph G(n);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  edge_adder adder(G);

  int cost = 0;
  int prev = 0;
  for(int i= 0; i< n-1; i++)
  {
    int c; std::cin >>c;
    cost += 129*c;
    adder.add_edge(i,i+1,c,129);
    if(c-prev > 0)
      adder.add_edge(source,i,c-prev,0);
    else if(c!= prev)
      adder.add_edge(i,sink,prev-c,0);

    prev = c;
  }

  adder.add_edge(n-1,sink,prev,0);

  for(int i = 0; i< m; i++)
  {
    int a,b,d; std::cin >> a >> b >> d;
    adder.add_edge(a,b,1,129*(b-a) -d);
  }

  boost::successive_shortest_path_nonnegative_weights(G, source, sink);
  int cost2 = boost::find_flow_cost(G);

  std::cout << cost -cost2 << "\n";

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for (size_t i = 0; i < T; i++) {
    solve();
  }
}
