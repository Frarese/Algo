#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

typedef std::vector<int> Vi;
typedef std::vector<std::pair<int,int>> Vp;
typedef std::vector<Vp> VVp;

void punch()
{
  int n,k; std::cin >> n >> k;
  Vp bev(n+1, {0,0});
  for(size_t i = 1; i<= n; i++)
  {
    int c,v; std::cin >> c >> v;
    bev[i] = std::make_pair(c,v);
  }
  VVp mem(n + 1 , Vp(k + 1, {0,0}));
  for(int i=0;i<=n;++i) mem[i][0] = std::make_pair(0,0);
  for(int i=1;i<=k;++i) mem[0][i] = std::make_pair(INT_MAX/2  ,-200);

  for(int i = 1; i<= n; i++)
    for(int j = 1; j<= k; j++)
    {
        mem[i][j] = mem[i-1][j];

        for(int z = 0; z <=1; ++z)
        {
          std::pair<int,int> x = mem[i-z][std::max(0, j- bev[i].second)];
          if(x.first + bev[i].first < mem[i][j].first)
          {
            mem[i][j].first = x.first + bev[i].first;
            mem[i][j].second = x.second + z;
          }
          else if (x.first + bev[i].first == mem[i][j].first)
            mem[i][j].second = std::max(x.second +z, mem[i][j].second);
        }

    }
    std::cout << mem[n][k].first << " " << mem[n][k].second << '\n';
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for(size_t i = 0; i< T; i++)
    punch();

  return 0;
}
