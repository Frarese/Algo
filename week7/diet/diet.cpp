#include<iostream>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include<vector>
#include<cmath>

typedef std::vector<std::pair<int,int>> Vp;
typedef std::vector<int> V;
typedef std::vector<V> Vv;
typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<int> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void diet(int n, int m)
{
  Vp nutr(n); V cost(m); Vv cal(m, V(n));
  for(size_t i = 0; i< n; i++){
    int l,u; std:: cin >> l >> u;
    nutr[i] = std::make_pair(l,u);
  }
  for(int i = 0; i< m; i++){
    std::cin >> cost[i];
    for(int j = 0; j < n; j++){
      std::cin >> cal[i][j];
    }
  }
  Program lp (CGAL::SMALLER, true, 0, false, 0);

  for(int i = 0; i < n; i ++){
    for(int j = 0; j < m; j++){
      lp.set_a( j, i*2, cal[j][i]);
      lp.set_a( j, i*2 +1, -1*cal[j][i]);
    }
    lp.set_b(i*2, nutr[i].second);
    lp.set_b(i*2 + 1, -1*nutr[i].first);
  }
  for(int i = 0; i< m; i++)
    lp.set_c(i, cost[i]);

  Solution s = CGAL::solve_linear_program(lp, ET());
  assert(s.solves_linear_program(lp));

  if(s.is_infeasible() || s.is_unbounded())
    std::cout << "No such diet.\n";
  else
    std::cout << std::floor(CGAL::to_double(s.objective_value())) << "\n";
}



int main()
{
  std::ios_base::sync_with_stdio(false);
  int m,n; bool done = false;
  while(!done)
  {
    std::cin >> n >> m;
    if(n != 0)
      diet(n,m);
    else
      done = true;
  }
}
