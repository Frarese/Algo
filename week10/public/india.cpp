#include <iostream>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/cycle_canceling.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                boost::property <boost::edge_weight_t, long> > > > > graph; // new! weightmap corresponds to costs

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

void india()
{
  int c,g,b,k,a; std::cin >> c >> g >> b >> k >> a;
  graph G(c);
  int source = boost::add_vertex(G);
  edge_adder adder(G);
  auto c_map = boost::get(boost::edge_capacity, G);
  auto r_map = boost::get(boost::edge_reverse, G);
  auto rc_map = boost::get(boost::edge_residual_capacity, G);

  for(int i = 0; i< g; i++)
  {
    int x,y,d,e; std::cin >> x >> y >> d >> e;
    adder.add_edge(x,y,e,d);
  }

  int cap = 1;
  bool done = false;
  adder.add_edge(source,k,1,0);

  while(!done)
  {
    edge_desc ex = boost::edge(source,k,G).first;
    c_map[ex] = cap;
    boost::successive_shortest_path_nonnegative_weights(G, source, a);
    int cost2 = boost::find_flow_cost(G);
    int s_flow = 0;
    out_edge_it e, eend;
    for(boost::tie(e, eend) = boost::out_edges(boost::vertex(source,G), G); e != eend; ++e) {
        s_flow += c_map[*e] - rc_map[*e];
    }
    if(s_flow == cap)
    {
      if( cost2 <= b)
        cap = cap*2;
      else
        done = true;
    }
    else
    {
      if(cost2 <= b)
        {
          std::cout << s_flow << "\n";
          return;
        }
      else
        {
          cap = s_flow;
          done = true;
        }
    }
  }

  int upper = cap, lower = cap/2;
  done = false;

  //Ali search
  while(!done)
  {
    int q = (lower +upper)/2;
    if(q == lower)
      done = true;
    edge_desc ex = boost::edge(source,k,G).first;
    c_map[ex] = q;
    boost::successive_shortest_path_nonnegative_weights(G, source, a);
    int cost2 = boost::find_flow_cost(G);
    if( cost2 <= b)
      lower = q;
    else if(cost2 > b)
      upper = q;
  }
  std::cout << lower << "\n";

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for (size_t i = 0; i < T; i++) {
    india();
  }
}
