#include<iostream>
#include<vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::no_property, boost::property<boost::edge_weight_t, int> >      Graph;
typedef boost::property_map<weighted_graph, boost::edge_weight_t>::type weight_map;

void solve()
{
	int k; std::cin >> k;
	Graph(k*(k+1)/2)

	int count = 0;
	for(int i = 1; i< k; i++)
		for(int j = 0; j< i; j++)
		{
			int v; std::cin >> v;
			if(j+1<i)
				boost::add_edge(count,count+1,v);
			if(j-1 > 0)
				boost::add_edge(count,count-1,v);
			if(i+1<k)
			{
				boost::add_edge(count,count+i,v);
				boost::add_edge(count,count+i+1,v);
			}
			if(i-1> 0)
				boost::add_edge(count,count+1-i,v);

		}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t; std::cin > t;
	while(t--)
		solve();

}
