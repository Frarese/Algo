#include<iostream>
#include<vector>
#include<map>
#include<boost/graph/adjacency_list.hpp>
#include <boost/graph/successive_shortest_path_nonnegative_weights.hpp>
#include <boost/graph/find_flow_cost.hpp>

typedef boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
    boost::property<boost::edge_capacity_t, long,
        boost::property<boost::edge_residual_capacity_t, long,
            boost::property<boost::edge_reverse_t, traits::edge_descriptor,
                boost::property <boost::edge_weight_t, long> > > > > graph; // new! weightmap corresponds to costs

typedef boost::graph_traits<graph>::edge_descriptor             edge_desc;
typedef std::vector<edge_desc> Ve;
typedef std::map<int, int> Mii;

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
  int n,s; std::cin >> n >> s;
  graph G(2*s);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  edge_adder adder(G);
  auto rc_map = boost::get(boost::edge_residual_capacity, G);
  std::vector<Mii> maps(s);

  long cars = 0;
  for(int i = 0; i< s; i++)
  {
    int l; std::cin >> l;
    cars += l;
    adder.add_edge(source,2*i,l,0);
    adder.add_edge(2*i+1,sink,1000,0);
    maps[i][0] = 2*i;
    maps[i][100000] = 2*i+1;
  }

  for(int i = 0; i< n; i++)
  {
    int si,t,d,a,p; std::cin >> si >> t >> d >> a >>p;
    si--; t--;
    if(!maps[si].count(d))
      maps[si][d] = boost::add_vertex(G);
    if(!maps[t].count(a))
      maps[t][a] = boost::add_vertex(G);

      adder.add_edge(maps[si][d], maps[t][a],1, (a-d)*100 - p);
  }

  for(int i = 0; i< s; i++)
  {
    auto it1 = maps[i].begin();
    int st = it1->first; int vr = it1->second;
    it1++;
    while(it1!=maps[i].end())
    {
      int st2 = it1->first; int vr2 = it1->second;
      adder.add_edge(vr,vr2, 1000, (st2 - st)*100);
      st = st2; vr = vr2;
      it1++;
    }
  }
  boost::successive_shortest_path_nonnegative_weights(G,source,sink);
  long cost =  cars*100000*100 - boost::find_flow_cost(G) ;
  std::cout <<  cost << "\n";

}


int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
