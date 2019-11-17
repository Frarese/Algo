#include<iostream>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include<cmath>

typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<int> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;


int main()
{
  std::ios_base::sync_with_stdio(false);
  int n; std::cin >> n;
  do{
    int d; std::cin >> d;
    Program lp(CGAL::SMALLER, false, 0, false, 0);
    for(int i = 0; i< n; i++)
    {
      int sqn = 0;
      for(int j = 0; j< d; j++)
      {
        int ai; std::cin >> ai;
        sqn += ai*ai;
        lp.set_a(j,i,ai);
      }
      int norm = std::floor(std::sqrt(sqn));
      lp.set_a(d,i, norm);
      int bi; std::cin >> bi;
      lp.set_b(i,bi);
    }
    lp.set_c(d, -1);
    lp.set_l(d,true,0);

    Solution s = CGAL::solve_linear_program(lp, ET());
    if(s.is_infeasible())
      std::cout << "none\n";
    else if(s.is_unbounded())
      std::cout << "inf\n";
    else
    std::cout << -(s.objective_value().numerator() / s.objective_value().denominator()) << "\n";
    std::cin >> n;
  }while(n> 0);
}
