#include<iostream>
#include<vector>
#include<climits>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
	boost::no_property,
	boost::property<boost::edge_weight_t, int>> Graph;

typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;


void paths(int n, int m, int q)
{
	std::vector<std::pair<int,int>> coor(n);
	Graph G(n);
	WeightMap w = boost::get(boost::edge_weight, G);


	for(int i = 0; i< n; i++)
	{
		long lat, lon;
		std::cin >> lon >> lat;
		coor[i] = std::make_pair(lon,lat);
	}

	for(int i = 0; i< m; i++)
	{
		int a,b,c; std::cin >> a >> b >> c;
		Edge e =boost::add_edge(a,b,G).first;
		w[e] = c;
	}	
	
	for(int i = 0; i< q; i++)
	{
		int s, t; std::cin >> s >> t;
		std::vector<int> dist_map(n);
		boost::dijkstra_shortest_paths(G,s,
			boost::distance_map(boost::make_iterator_property_map(
			dist_map.begin(), boost::get(boost::vertex_index, G))));

		if(dist_map[t] != INT_MAX)
			std::cout << dist_map[t] << "\n";
		else
			std::cout << "unreachable" << "\n";
	}
}


int main()
{

	std::ios_base::sync_with_stdio(false);
	int  n, m, q;
		std::cin >> n >> m >> q;
		paths(n,m,q);
	return 0;
}
