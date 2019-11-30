#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<climits>
// BGL includes
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/push_relabel_max_flow.hpp>
#include <boost/tuple/tuple.hpp>

typedef	boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
	boost::property<boost::edge_capacity_t, long,
		boost::property<boost::edge_residual_capacity_t, long,
			boost::property<boost::edge_reverse_t, traits::edge_descriptor> > > >	graph;
// Interior Property Maps
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

void coon()
{
  int n,m; std::cin >> n >> m;
  graph G(n);
  edge_adder adder(G);
	auto rc_map = boost::get(boost::edge_residual_capacity, G);

  for (size_t i = 0; i < m; i++) {
    int u,v,c; std::cin >> u >> v >> c;
    adder.add_edge(u,v,c);
  }
  std::pair<int,int> best;
  int bestFlow = INT_MAX;
  for(size_t i = 0; i< n; i++){
    int flow = push_relabel_max_flow(G, i, (i+1)%n);
    if(flow < bestFlow){
      bestFlow = flow;
      best = std::make_pair(i, (i+1)%n);
    }
  }

  int flow = push_relabel_max_flow(G, best.first, best.second);

  int count = 1;
  std::vector<int> vis(n, false); // visited flags
  std::queue<int> Q; // BFS queue (from std:: not boost::)
  vis[best.first] = true; // Mark the source as visited
  Q.push(best.first);
  while (!Q.empty()) {
    const int u = Q.front();
    Q.pop();
    out_edge_it ebeg, eend;
    for (boost::tie(ebeg, eend) = boost::out_edges(u, G); ebeg != eend; ++ebeg) {
      const int v = boost::target(*ebeg, G);
      // Only follow edges with spare capacity
      if (rc_map[*ebeg] == 0 || vis[v]) continue;
      vis[v] = true; count++;
      Q.push(v);
    }
  }

  std::cout << flow << "\n";
  std::cout << count;
  for (size_t i = 0; i < n; i++) {
    if(vis[i])
      std::cout << " " << i;
  }
  std::cout << '\n';

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for (size_t i = 0; i < T; i++)
    coon();
}
