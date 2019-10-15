#include<iostream>
#include<vector>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/kruskal_min_spanning_tree.hpp>
#include<boost/graph/dijkstra_shortest_paths.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
	boost::no_property, boost::property<boost::edge_weight_t, int>> G;
typedef boost::graph_traits<G>::edge_descriptor edge_desc;
typedef boost::property_map<G,boost::edge_weight_t>::type W;
typedef boost::graph_traits<G>::vertex_descriptor vertex_desc;

void tree(int n, int m)
{
	G g(n);
	std::vector<edge_desc> mst;
	std::vector<int> dist_map(n);
	std::vector<vertex_desc> pred_map(n);
	W weights = boost::get(boost::edge_weight, g);
	int a,b,w;
	for(int i = 0; i< m; ++i)
	{
		edge_desc e;
		std::cin >> a >> b >> w;
		e = boost::add_edge(a,b,g).first; weights[e] = w;
	}
	
	boost::kruskal_minimum_spanning_tree(g, std::back_inserter(mst));
	boost::dijkstra_shortest_paths(g, 0,
		boost::distance_map(boost::make_iterator_property_map(
		dist_map.begin(),boost::get(boost::vertex_index,g)))
		.predecessor_map(boost::make_iterator_property_map(
		pred_map.begin(),boost::get(boost::vertex_index,g)))
	       	);

	int result = 0;

	for(std::vector<edge_desc>::iterator it = mst.begin(); it != mst.end(); ++it)
		result += weights[*it];

	std::cout << result << " " << *std::max_element(dist_map.begin(), dist_map.end()) << "\n";
	

}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n,m;
	std::cin >> T;
	for(int i = 0; i< T; ++i)
	{
		std::cin >> n >> m;
		tree(n,m);
	}
	return 0;
}
