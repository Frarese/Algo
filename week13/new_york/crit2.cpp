#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include <sys/resource.h>

typedef std::vector<int> Vi;
typedef std::vector<Vi> Vvi;
typedef std::set<int> Si;
typedef std::multiset<int> Mi;
typedef std::queue<int> Qi;

inline void rec(int pos, const int m, const int k, const Vi &parent, Qi &route, Mi &temp, const Vi &temps, Si &w)
{
  //std::cerr << pos <<"\n";
  route.push(pos);
  temp.insert(temps[pos]);
  if(route.size() > m)
  {
    temp.erase(temp.find(temps[route.front()]));
    route.pop();
  }
  if(route.size() == m)
  {
    auto it1 = temp.begin();
    auto it2 = temp.end(); it2--;

    //std::cerr << *it1 << " " << *it2 << "\n";
    if(*it2 - *it1 <= k)
      w.insert(pos);
  }
  if(pos!= 0)
    rec(parent[pos],m,k,parent,route,temp,temps,w);

}

void solve()
{
  int n,m,k; std::cin >> n >> m >>k;
  Vi temps(n);

  for(int i = 0; i< n; i++)
    std::cin >> temps[i];

  Vvi routes(n);
  Vi parent(n);
  for(int i = 0; i< n-1; i++)
  {
    int u,v; std::cin >> u >> v;
    routes[u].push_back(v);
    parent[v] = u;
  }

  bool done = false;

  //std::cerr << "I die after this point\n";
  Qi route;
  Mi temp;
  Si w; //std::cerr << w.max_size() << "\n";
  for(int i = 0; i< routes.size(); i++)
    if(routes[i].size() == 0)
    {
      while(!route.empty())
          route.pop();
        temp.clear();
      bool done = false;
      route.push(i);
      temp.insert(temps[i]);

      while(!done)
      {
        if(route.size() > m)
        {
          auto itr = temp.find(temps[route.front()]);
          if(itr!=temp.end()){
            temp.erase(itr);
          }

          route.pop();
        }
        if(route.size() == m)
        {
          auto it1 = temp.begin();
          auto it2 = temp.end(); it2--;

          //std::cerr << *it1 << " " << *it2 << "\n";
          if(*it2 - *it1 <= k)
            w.insert(route.back());
        }
        if(route.back() != 0)
          {
            route.push(parent[route.back()]);
            temp.insert(temps[parent[route.back()]]);
          }
        else
            done = true;
      }
    /*  while(!route.empty())
        route.pop();
      temp.clear();
      rec(i,m,k,parent,route,temp,temps,w);*/
    }


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
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
        }
    }
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
