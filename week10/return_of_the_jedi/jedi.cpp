#include <iostream>
#include <vector>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/visitors.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
    boost::no_property, boost::property<boost::edge_weight_t, int> > Graph;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_iterator EdgeIt;
typedef boost::graph_traits<Graph>::out_edge_iterator OutEdgeIt;
typedef boost::property_map<Graph, boost::edge_weight_t>::type  WeightMap;

using namespace std;

vector< vector<int> > max_edges;
WeightMap MSTweightmap;

struct my_vis : boost::default_dfs_visitor {
    int start_edge;

    void start_vertex(Vertex &v, Graph const &G) {
        max_edges[v][v] = 0;
        start_edge = v;

        boost::default_dfs_visitor::start_vertex(v, G);
    }

    void tree_edge(Edge const &e, Graph const &G) {
        // cout << "edge: " << source(e, G) << "-" << target(e, G) << endl;
        // cout << "last edge: " << MSTweightmap[e] << endl;
        // cout << "biggest of last edge: " << max_edges[start_edge][source(e, G)] << endl;
        max_edges[start_edge][target(e, G)] = max(MSTweightmap[e], max_edges[start_edge][source(e, G)]);

        boost::default_dfs_visitor::tree_edge(e, G);
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int z = 0; z < t; ++z) {
        int n, o;
        cin >> n >> o;

        Graph G(n);
        WeightMap weightmap = boost::get(boost::edge_weight, G);

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                Edge e; bool succ;
                boost::tie(e, succ) = boost::add_edge(i, j, G);
                cin >> weightmap[e];
            }
        }

        

        vector<Edge> mst;
        boost::kruskal_minimum_spanning_tree(G, back_inserter(mst));

        int min_diff = INT_MAX;
        int sum = 0;

        Graph MST(n);
        MSTweightmap = boost::get(boost::edge_weight, MST);

        for (int i = 0; i < mst.size(); ++i) {
            Edge e; bool succ;
            boost::tie(e, succ) = boost::add_edge(source(mst[i], G), target(mst[i], G), MST);
            MSTweightmap[e] = weightmap[mst[i]];
            sum += weightmap[mst[i]];
            boost::remove_edge(mst[i], G);
        }

        max_edges = vector<vector<int> >(n, vector<int>(n));

        my_vis vis;
        for (int i = 0; i < n; ++i) {
            boost::depth_first_search(MST, visitor(vis).root_vertex(i));
        }


        EdgeIt ebeg, eend;
        for (boost::tie(ebeg, eend) = boost::edges(G); ebeg != eend; ++ebeg) {
            // cout << "weight map " << weightmap[*ebeg] << endl;
            // cout << "max edges " << max_edges[source(*ebeg, G)][target(*ebeg, G)] << endl;
            min_diff = min(min_diff, weightmap[*ebeg] - max_edges[source(*ebeg, G)][target(*ebeg, G)]);
        }
        // cout << "sum " << sum << endl;
        // cout << "min diff " << min_diff << endl;

        cout << sum + min_diff << endl;

    }


    return 0;
}
