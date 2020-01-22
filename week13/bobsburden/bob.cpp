#include<iostream>
#include<vector>
#include<climits>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

typedef std::vector<std::vector<std::pair<int,int>>> Vvp;

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      Graph;
typedef boost::property_map<Graph, boost::edge_weight_t>::type weight_map;
typedef boost::graph_traits<Graph>::edge_descriptor            Edge;

void solve()
{
	int k; std::cin >> k;
  const int NUMVERT = k*(k+1);
  Graph G(NUMVERT);
  weight_map w = boost::get(boost::edge_weight, G);
  std::vector<int> mas(NUMVERT/2);

  int count = 0;
  for(int i = 1; i<=k; i++)
    for(int j = 0; j< i; j++)
    {
      int p; std::cin >> p;
      mas[count] = p;
      Edge e = boost::add_edge(2*count, 2*count +1,G).first; w[e]= p;

      if(i!= k)
      {
          e = boost::add_edge(2*count +1, 2*(count+i),G).first; w[e]= 0;
          e = boost::add_edge(2*count +1, 2*(count+i+1) ,G).first; w[e]= 0;
          e = boost::add_edge(2*(count+i) +1, 2*count,G).first; w[e]= 0;
          e = boost::add_edge( 2*(count+i+1)+1, 2*count ,G).first; w[e]= 0;
      }
      if(j!= 0)
        e = boost::add_edge(2*count+1, 2*(count-1),G).first; w[e]= 0;

      if(j!= i-1)
        e = boost::add_edge(2*count+1, 2*(count+1),G).first; w[e]= 0;

      count++;
    }
    std::vector<int> dist_map1(NUMVERT), dist_map2(NUMVERT), dist_map3(NUMVERT);

    boost::dijkstra_shortest_paths(G, 0,
  		boost::distance_map(boost::make_iterator_property_map(
  		dist_map1.begin(),boost::get(boost::vertex_index,G))));

      boost::dijkstra_shortest_paths(G, k*(k+1)-2,
    		boost::distance_map(boost::make_iterator_property_map(
    		dist_map2.begin(),boost::get(boost::vertex_index,G))));

      boost::dijkstra_shortest_paths(G, k*(k-1),
      	boost::distance_map(boost::make_iterator_property_map(
      	dist_map3.begin(),boost::get(boost::vertex_index,G))));

      int best = INT_MAX;
    for(int i = 1; i< NUMVERT; i=i+2)
    {
      int res = dist_map1[i] + dist_map2[i] + dist_map3[i] - 2*mas[i/2];
      best = std::min(best, res);
    }

    std::cout << best <<"\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t; std::cin >> t;
	while(t--)
		solve();

}
