#include<iostream>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/strong_components.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#include<vector>
#include<climits>
#include<algorithm>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      Graph;
typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
typedef boost::graph_traits<Graph>::edge_descriptor            Edge;
typedef boost::graph_traits<Graph>::vertex_descriptor          Vertex;
typedef std::vector<int> Vi;

void planet()
{
  int n,m,k,T; std::cin >> n>> m >> k >> T;
  Graph G(n);
  WeightMap w = boost::get(boost::edge_weight, G);

  Vi tel(T);
  for(int i = 0; i< T; i++)
    std::cin >> tel[i];

  for(int i = 0; i< m; i++)
  {
    int u,v,c; std::cin >> u >> v >> c;
    Edge e = boost::add_edge(v,u,G).first;
    w[e] = c;
  }
  Vi scc_map(n);
  int nscc = boost::strong_components(G,boost::make_iterator_property_map(scc_map.begin(), boost::get(boost::vertex_index, G)));

  Vi tele(nscc,0);
  for(int i = 0; i< nscc; i++)
    boost::add_vertex(G);

  for(int i = 0; i< T; i++)
  {
     int t = tel[i];
     Edge e = boost::add_edge(t, n+ scc_map[t], G).first;
     w[e] = 0;
     tele[scc_map[t]]++;
  }

  for(int i = 0; i<T; i++)
  {
    int t = tel[i];
    Edge e = boost::add_edge( n+ scc_map[t], t, G).first;
    w[e] = tele[scc_map[t]] -1;
  }

  Vi dist_map(boost::num_vertices(G));

  boost::dijkstra_shortest_paths(G, n-1,boost::distance_map(boost::make_iterator_property_map(dist_map.begin(), boost::get(boost::vertex_index, G))));

  int minD = INT_MAX;
  for(int i = 0; i< k; i++)
    minD = std::min(minD, dist_map[i]);

  if(minD <= 1000000)
    std::cout << minD << "\n";
  else
    std::cout << "no\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(int i = 0; i< T; i++)
    planet();
  return 0;
}
