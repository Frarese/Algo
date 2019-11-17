#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

typedef std::vector<std::pair<int,int>> Vp;

bool cmp(std::pair <int, int> j1, std::pair <int, int> j2) {
	return j1.second < j2.second;
}

int get_min_overlaps_point(Vp &jedi, int n) {
	std::map <int, int> counter;
	counter[0] = 0;
	for (int i = 0; i < n; i++) {
		if (!counter.count(jedi[i].first)) counter[jedi[i].first] = 0;
		if (!counter.count(jedi[i].second)) counter[jedi[i].second] = 0;
		counter[jedi[i].first]++;
		counter[jedi[i].second]--;
		if (jedi[i].first > jedi[i].second) counter[0]++;
	}

	int min_overlaps = n;
	int crt_overlaps = 0;
	int min_point = 0;
	for (std::map <int, int> :: iterator it = counter.begin();
		 it != counter.end(); it++) {
		crt_overlaps += it->second;
		// cout << it->first << ' ' << crt_overlaps << '\n';
		if (crt_overlaps < min_overlaps) {
			min_overlaps = crt_overlaps;
			min_point = it->first;
		}
	}
	return min_point;
}

void fix_jedis(int min_point, Vp &overlapping, Vp &non_overlapping, Vp &jedi, int n, int m) {
	for (int i = 0; i < n; i++) {
		int a = jedi[i].first;
		int b = jedi[i].second;
		if (jedi[i].first > min_point)
			jedi[i].first -= min_point;
		else jedi[i].first += m - min_point;
		if (jedi[i].second > min_point)
			jedi[i].second -= min_point;
		else jedi[i].second += m - min_point;

		if (a <= b && a <= min_point && min_point <= b) {
			overlapping.push_back(jedi[i]);
			continue;
		}
		if (a > b && (a <= min_point || min_point <= b)) {
			overlapping.push_back(jedi[i]);
			continue;
		}

		non_overlapping.push_back(jedi[i]);
	}
}


int find(Vp &non_overlapping, int last_point, int end_at) {
	int cnt = 0;
	for (int i = 0; i < non_overlapping.size(); i++) {
		if (non_overlapping[i].first > last_point &&
			non_overlapping[i].second < end_at) {
			cnt++;
			last_point = non_overlapping[i].second;
		}

	}

	return cnt;
}

void clones()
{
  int n, m; std::cin >> n >> m;
  Vp jedi(n), overlapping, non_overlapping;
  for(int i = 0; i< n; i++){
    int a,b; std::cin >> a >> b;
    a--; b--;
    jedi[i] = std::make_pair(a,b);
  }
    int min_p = get_min_overlaps_point(jedi, n);
    fix_jedis(min_p, overlapping, non_overlapping, jedi, n, m);

  std::sort(non_overlapping.begin(), non_overlapping.end(), cmp);

  int sol = find(non_overlapping, -1, m);
  for (int i = 0; i < overlapping.size(); i++) {
    sol = std::max(sol, 1 + find(non_overlapping,overlapping[i].second % m, overlapping[i].first));
  }

  std::cout << sol << '\n';
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(int i = 0; i < T; i++)
    clones();

  return 0;
}
