#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>

typedef std::vector<int> Vi;
typedef std::vector<Vi> Vvi;
typedef std::set<int> Si;

void rec(int pos, const int m, const int k, Vi &route, const Vvi &routes, Vi &temp, const Vi &temps, Si &w)
{
  std::cerr << pos <<"\n";
  route.push_back(pos);
  temp.push_back(temps[pos]);
  if(route.size() >= m)
  {
    int top = *std::max_element(temp.end() -m, temp.end());
    int low = *std::min_element(temp.end() -m , temp.end());
    if(top-low <= k)
      w.insert(route[route.size()-m]);
  }

  for(int i = 0; i< routes[pos].size(); i++)
    rec(routes[pos][i],m,k,route,routes,temp,temps,w);

  route.pop_back();
  temp.pop_back();
}

void solve()
{
  int n,m,k; std::cin >> n >> m >>k;
  Vi temps(n);

  for(int i = 0; i< n; i++)
    std::cin >> temps[i];

  Vvi routes(n);
  for(int i = 0; i< n-1; i++)
  {
    int u,v; std::cin >> u >> v;
    routes[u].push_back(v);
  }


  std::cerr << "I die after this point\n";
  Vi route, temp; Si w;
  rec(0,m,k,route,routes,temp,temps,w);

  if(w.size() == 0)
    std::cout << "Abort mission\n";
  else{
    for(auto it = w.begin(); it!= w.end(); it++)
      std::cout << *it << " ";
    std::cout << "\n";
  }


}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
