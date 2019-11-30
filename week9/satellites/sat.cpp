#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>

typedef	boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
	boost::property<boost::edge_capacity_t, long,
		boost::property<boost::edge_residual_capacity_t, long,
			boost::property<boost::edge_reverse_t, traits::edge_descriptor> > > >	graph;

typedef	boost::graph_traits<graph>::edge_descriptor			edge_desc;
typedef	boost::graph_traits<graph>::out_edge_iterator			out_edge_it;

class edge_adder {
 graph &G;

 public:
  explicit edge_adder(graph &G) : G(G) {}

  void add_edge(int from, int to, long capacity) {
    auto c_map = boost::get(boost::edge_capacity, G);
    auto r_map = boost::get(boost::edge_reverse, G);
    const edge_desc e = boost::add_edge(from, to, G).first;
    const edge_desc rev_e = boost::add_edge(to, from, G).first;
    c_map[e] = capacity;
    c_map[rev_e] = 0; // reverse edge has no capacity!
    r_map[e] = rev_e;
    r_map[rev_e] = e;
  }
};

void sat()
{
  int g,s,l; std::cin >> g >> s >> l;
  graph G(g+s);
  int source = boost::add_vertex(G);
  int sink = boost::add_vertex(G);
  edge_adder adder(G);
  auto rc_map = boost::get(boost::edge_residual_capacity, G);

  for(size_t i = 0; i< g; i++)
    adder.add_edge(source,i,1);

    for(size_t i = 0; i< s; i++)
      adder.add_edge(g+i,sink,1);


  for(size_t i = 0; i< l; i++)
  {
    int u,v; std::cin >> u >> v;
    adder.add_edge(u,g+v,1);
  }
  long max_flow = boost::push_relabel_max_flow(G,source,sink);

  std::vector<int> vis(g+s+2, false); // visited flags
  std::queue<int> Q; // BFS queue (from std:: not boost::)
  vis[source] = true; // Mark the source as visited
  Q.push(source);
  while (!Q.empty()) {
    const int u = Q.front();
    Q.pop();
    out_edge_it ebeg, eend;
    for (boost::tie(ebeg, eend) = boost::out_edges(u, G); ebeg != eend; ++ebeg) {
      const int v = boost::target(*ebeg, G);
      // Only follow edges with spare capacity
      if (rc_map[*ebeg] == 0 || vis[v]) continue;
      vis[v] = true;
      Q.push(v);
    }
  }
  
  int L=0;
  	for(int i=0;i<g;++i) if(!vis[i]) ++L;
  	int R=0;
  	for(int i=0;i<s;++i) if(vis[g+i]) ++R;

    std::cout << L << " " << R << std::endl;
    for(int i=0;i<g;++i) if(!vis[i]) std::cout << i << " ";
    for(int i=0;i<s;++i) if(vis[g+i]) std::cout << i << " ";

  	std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(size_t i = 0; i< T; i++)
    sat();
}
