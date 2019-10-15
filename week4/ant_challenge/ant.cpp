#include<iostream>
#include<vector>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>
#include<boost/graph/prim_minimum_spanning_tree.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
		boost::no_property,
		boost::property<boost::edge_weight_t, int> > Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef boost::graph_traits<Graph>::edge_iterator EdgeIt;
typedef boost::property_map<Graph, boost::edge_weight_t>::type WeightMap;


void ants(int n, int e, int s, int a, int b)
{
	std::vector<Graph> G(s, Graph(n));
	std::vector<WeightMap> weights(s);
	
	for(int i = 0; i< e; i++)
	{
		int u, v;
		std::cin >> u >> v;

		for(int j = 0; j< s; j++)
		{
			int w;
			std::cin >> w;
			Edge e = boost::add_edge(u,v,G[j]).first;
			if(i == 0)
				weights[j] = boost::get(boost::edge_weight, G[j]);
			weights[j][e] = w;
		}
	}

	std::vector<int> hives(s);

	for(int i = 0; i< s; i++)
	{
		std::cin >> hives[i];
	}

	std::vector<std::vector<Vertex>> pred_maps(s, std::vector<Vertex>(n));

	for(int i = 0; i< s; ++i)
	{
		boost::prim_minimum_spanning_tree(G[i],
			boost::make_iterator_property_map(pred_maps[i].begin(),
			boost::get(boost::vertex_index, G[i])),
			boost::root_vertex(hives[i]));
	}

	Graph forest(n);
	WeightMap forest_w = boost::get(boost::edge_weight, forest);

	for(int i = 0; i< s; i++)
	{
		for(int j = 0; j< n; j++)
		{
			if(pred_maps[i][j] != j)
			{
				Edge e; bool s;
				std::tie(e,s) = boost::edge(j, pred_maps[i][j], G[i]);
				
				Edge e1 = boost::add_edge(boost::source(e,G[i]), boost::target(e, G[i]), forest).first;
				forest_w[e1] = weights[i][e];
			}
		}
	}

	std::vector<Vertex> pred_map(n);
	std::vector<int> dist_map(n);
	boost::dijkstra_shortest_paths(forest, a,
		boost::predecessor_map(boost::make_iterator_property_map(pred_map.begin(), boost::get(boost::vertex_index, forest))).distance_map(boost::make_iterator_property_map(dist_map.begin(), boost::get(boost::vertex_index, forest))));

	std::cout << dist_map[b] << "\n";

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n, e, s, a, b;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n >> e >> s >> a >> b;
		ants(n,e,s,a,b);
	}
	return 0;

}
