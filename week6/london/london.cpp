#include<iostream>
#include <vector>

#include<boost/graph/adjacency_list.hpp>
#include<boost/graph/push_relabel_max_flow.hpp>

using namespace std;

typedef	boost::adjacency_list_traits<boost::vecS, boost::vecS, boost::directedS> Traits;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property,
	boost::property<boost::edge_capacity_t, long,
		boost::property<boost::edge_residual_capacity_t, long,
			boost::property<boost::edge_reverse_t, Traits::edge_descriptor> > > >	Graph;
typedef	boost::property_map<Graph, boost::edge_capacity_t>::type		EdgeCapacityMap;
typedef	boost::property_map<Graph, boost::edge_residual_capacity_t>::type	ResidualCapacityMap;
typedef	boost::property_map<Graph, boost::edge_reverse_t>::type		ReverseEdgeMap;
typedef	boost::graph_traits<Graph>::vertex_descriptor			Vertex;
typedef	boost::graph_traits<Graph>::edge_descriptor			Edge;
typedef	boost::graph_traits<Graph>::edge_iterator			EdgeIt;


class EdgeAdder {
	Graph &G;
	EdgeCapacityMap	&capacitymap;
	ReverseEdgeMap	&revedgemap;

public:
	EdgeAdder(Graph & G, EdgeCapacityMap &capacitymap, ReverseEdgeMap &revedgemap):
		G(G), capacitymap(capacitymap), revedgemap(revedgemap){}

	void addEdge(int from, int to, long capacity) {
		Edge e, rev_e;
		bool success;
		boost::tie(e, success) = boost::add_edge(from, to, G);
		boost::tie(rev_e, success) = boost::add_edge(to, from, G);
		capacitymap[e] = capacity;
		capacitymap[rev_e] = 0;
		revedgemap[e] = rev_e;
		revedgemap[rev_e] = e;
	}
};

void london(int h, int w)
{
	vector<int> count(26,0);
	vector<vector<int>> node(26, vector<int>(26,0));

	string message;
	vector<string> front(h), back(h);
	Graph G(26);
	Vertex source = boost::add_vertex(G);
	Vertex sink = boost::add_vertex(G);
	EdgeCapacityMap capacitymap = boost::get(boost::edge_capacity, G);
	ReverseEdgeMap revedgemap = boost::get(boost::edge_reverse, G);
	ResidualCapacityMap rescapacitymap = boost::get(boost::edge_residual_capacity, G);
	EdgeAdder eaG(G, capacitymap, revedgemap);

	cin >> message;

	for(int i = 0; i < message.length(); i++)
	{
		count[message[i] -65]++;
		//eaG.addEdge(message[i] - 65, sink,1);
	}

	for(int i = 0; i< 26; i++)
	{
		eaG.addEdge(i,sink,count[i]);
	}

	for(int i = 0; i< h; i++)
		cin >> front[i];

	for(int i = 0; i< h; i++)
	{
		cin >> back[i];
		for(int j = 0; j< w; j++)
		{
				node[front[i][j]-65][back[i][w-j-1]-65]++;
		}
	}

	for(int i= 0; i< 26; i++)
	{
		for(int j = 0; j< 26; j++)
		{
			if(node[i][j] >0)
			{
				Vertex e = boost::add_vertex(G);
				if(i == j && edge(i,sink,G).second)
					eaG.addEdge(source,i,node[i][j]);
				else
				{	//if(edge(i,sink,G).second && edge(j,sink,G).second)
				//	{
						eaG.addEdge(source,e,node[i][j]);
						eaG.addEdge(e,i,node[i][j]);
						eaG.addEdge(e,j,node[i][j]);
				//	}
				//	else
				//		if(edge(i,sink,G).second)
				//			eaG.addEdge(source,i,node[i][j]);
				}
			}
		}
	}

		long flow = boost::push_relabel_max_flow(G,source,sink);
	if(flow == message.length())
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, h, w;
	cin >> T;
	for(int i = 0; i< T; i++)
	{
		cin >> h >> w;
		london(h,w);
	}
}
