 #include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

typedef std::vector<int> VI;
typedef std::vector<std::string> VS;
typedef std::vector<VI> VVI;
typedef std::vector<std::vector<std::pair<int, int> > > VVPII;
// Binary Search:
// Find the largest index i s.t. p(i) := age[path[i]] <= b is true
int binary(int b, const VI& path, const VI& age) {
	// Establish invariant
	int l = -1;// l is largest index where we know p(l) is false
	int r = (int)path.size() - 1;    // r is smallest index where we know p(r) is true

	while (l + 1 < r) {         // always at least one element strictly between
		int m = (l + r)/2;    // m != l and m != r so interval shrinks
		// Propagate invariant
		if (age[path[m]] <= b) r = m;
		else l = m;
	}
	return path[r];
}

// DFS
void dfs(int u, const VVI& tree, VI& path, const VVPII& query,        VI& result, const VI& age) {
	// Process queries
	for (int i = 0; i < (int)query[u].size(); ++i) {
		result[query[u][i].second] = binary(query[u][i].first, path, age);
	}
	// Continue dfs
	for (int i = 0; i < (int)tree[u].size(); ++i) {
		int v = tree[u][i];
		path.push_back(v);                             // Maintain path invariant
		dfs(v, tree, path, query, result, age);
	}
	path.pop_back();                                                      // Maintain path invariant
}
void testcase() {
	int n, q; std::cin >> n >> q;
	// Read names and ages
	std::map<std::string, int> species_to_index;
	VS species(n);
	VI age(n);
	for (int i = 0; i < n; ++i) {
		std::string name; std::cin >> name;
		species_to_index[name] = i;
		species[i] = name;
		std::cin >> age[i];
	}
	// Find root
	int root = std::max_element(age.begin(), age.end()) - age.begin();
	// Read tree
	VVI tree(n);
	for (int i = 0; i < n - 1; ++i) {
		std::string child; std::cin >> child;
		std::string parent; std::cin >> parent;
		tree[species_to_index[parent]].push_back(species_to_index[child]);
	}
	// Read queries:
	// for each species store a vector of queries consisting of  the age b and
	// the index of the query i
	VVPII query(n);
	for (int i = 0; i < q; ++i) {
		std::string name; std::cin >> name;
		int b; std::cin >> b;
		query[species_to_index[name]].push_back(std::make_pair(b,i));
	}
	// Process queries in one tree traversal
	VI path; path.push_back(root);                                                                                                                                                                                         // Initialise path invariant
	VI result(q);
	dfs(root, tree, path, query, result, age);

	// Output result
	for (int i = 0; i < q; ++i) {
		std::cout << species[result[i]];  if (i < q - 1) std::cout << " ";
	}
	std::cout << std::endl;
}
int main() {
	std::ios_base::sync_with_stdio(false);

	int t; std::cin >> t;
	for (int i = 0; i < t; ++i) {
		testcase();
	}
}
