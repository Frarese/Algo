#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/max_cardinality_matching.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

void buddie(int n, int c, int f)
{
	int count = 0;	
	std::map<std::string, int> carat;

	Graph G(n);
	std::vector<std::set<int>> student_c(n);

	for(int i = 0; i< n; i++)
	{
		std::set<int> ci;

		for(int j = 0; j < c; j++)
		{
			std::string car; std::cin >> car;
			if(carat.find(car) == carat.end())
			{
				carat[car] = count++;
			}
			ci.insert(carat[car]);
		}
		student_c[i] = ci;

		for(int j = 0; j< i; j++)
		{
			std::set<int> inters;
			std::set_intersection(student_c[i].begin(), student_c[i].end(),
					student_c[j].begin(), student_c[j].end(),
					std::inserter(inters, inters.begin()));
			if(inters.size() > f)
				boost::add_edge(i,j,G);	
		}
	}
	
	std::vector<Vertex> mate_map(n);
	boost::edmonds_maximum_cardinality_matching(G,
		boost::make_iterator_property_map(mate_map.begin(), boost::get(boost::vertex_index, G)));
	bool opt = false;

	for(int i = 0; i< n; i++)
		if(mate_map[i] == boost::graph_traits<Graph>::null_vertex())
			opt = true;
	
	if(opt)
		std::cout << "optimal" << "\n";
	else
		std::cout << "not optimal" << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n, c, f;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n >> c >> f;
		buddie(n,c,f);
	}
	return 0;
}
