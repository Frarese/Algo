#include<iostream>
#include<vector>
#include<cmath>
#include <iomanip>

typedef std::vector<double> Vd;
typedef std::vector<Vd> VVd;

double rec(int day, int money, const Vd &p, int goal, VVd &mem)
{
  if(money >= goal)
    return 1;
  if(day >= p.size() || money <= 0)
    return 0;

  if(mem[day][money] != -1)
    return mem[day][money];

    double result = 0;
     for (size_t i = 1; i <= money; i++) {
       result = std::max(result, p[day]*rec(day+1,money+i,p,goal,mem) + (1-p[day])*rec(day+1,money-i,p,goal,mem));
     }
     mem[day][money] = std::max(result, rec(day+1,money,p,goal,mem));
     return mem[day][money];
}

void solve()
{
  int n,m,k; std::cin >> n >> k >> m;
  Vd p(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> p[i];
  }
  VVd mem(n,Vd(m,-1));

  double best = rec(0,k,p,m, mem);
  std::cout << std::fixed << std::setprecision(5);
  std::cout << best << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while (t--) {
    solve();
  }
}
