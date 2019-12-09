#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<int> Vi;
typedef std::vector<std::vector<std::pair<int,int>>> Vvp;
typedef std::vector<Vi> Vv;

int minK;

int rec(int k, int u, Vv &mem, Vvp &adl)
{
  if(k== mem.size())
    return 0;

  if(mem[k][u] != -1)
    return mem[k][u];

  if(adl[u].size() == 0)
    return rec(k,0,mem,adl);

  int result = -1;
  for (size_t i = 0; i < adl[u].size(); i++) {
    result = std::max(result, rec(k+1, adl[u][i].first,mem,adl) + adl[u][i].second);
  }
  mem[k][u] = result;
  return mem[k][u];
}

void game()
{
  int n,m,k; long x; std::cin >> n >> m >> x >> k;
  Vvp adl(n);

  for (size_t i = 0; i < m; i++) {
    int u,v,p; std::cin >> u >> v >>p;
    adl[u].push_back(std::make_pair(v,p));
  }

  Vv mem(k, Vi(n,-1));

  long result = rec(0,0, mem, adl);

  for (size_t i = 1; i < k; i++) {
    rec(i,0,mem,adl);
  }


      for (size_t i = k-1; i >0; i--) {
        if(mem[i][0] >= x)
          {
            std::cout << k - i << "\n";
            return;
          }
    }

      std::cout << "Impossible\n";



}

int main() {
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while (t--) {
    game();
  }
  return 0;
}
