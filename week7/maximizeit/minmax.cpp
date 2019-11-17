#include<iostream>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include<cmath>

typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<int> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void maximize()
{
  int a,b; std::cin >> a >> b;

  Program lp (CGAL::SMALLER, true, 0, false, 0);

  const int X = 0;
  const int Y = 1;
  lp.set_a(X, 0,  1); lp.set_a(Y, 0, 1); lp.set_b(0, 4);
  lp.set_a(X, 1, 4); lp.set_a(Y, 1, 2); lp.set_b(1, a*b);
  lp.set_a(X, 2, -1); lp.set_a(Y, 2, 1); lp.set_b(2, 1);
  // objective function
  lp.set_c(Y, -1*b); lp.set_c(X, a);

  // solve the program, using ET as the exact type
  Solution s = CGAL::solve_linear_program(lp, ET());
  assert(s.solves_linear_program(lp));
  if(s.is_unbounded())
    std::cout << "unbounded\n";
  else if (s.is_infeasible())
    std::cout << "no\n";
  else
    std::cout << std::floor(-1* CGAL::to_double(s.objective_value())) << "\n";
}

void minimize()
{
  int a,b; std::cin >> a >> b;

  Program lp (CGAL::LARGER, false, 0, true, 0);

  const int X = 0;
  const int Y = 1;
  const int Z = 2;
  lp.set_a(X, 0, 1); lp.set_a(Y, 0, 1); lp.set_a(Z, 0, 0); lp.set_b(0, -4);
  lp.set_a(X, 1, 4); lp.set_a(Y, 1, 2); lp.set_a(Z, 1, 1); lp.set_b(1, -1*a*b);
  lp.set_a(X, 2,-1); lp.set_a(Y, 2, 1); lp.set_a(Z, 2, 0); lp.set_b(2, -1);
  // objective function
  lp.set_c(Y, b); lp.set_c(X, a); lp.set_c(Z, 1);

  // solve the program, using ET as the exact type
  Solution s = CGAL::solve_linear_program(lp, ET());
  assert(s.solves_linear_program(lp));
  if(s.is_unbounded())
    std::cout << "unbounded\n";
  else if (s.is_infeasible())
    std::cout << "no\n";
  else
    std::cout << std::ceil(CGAL::to_double(s.objective_value())) << "\n";
}
int main()
{
  std::ios_base::sync_with_stdio(false);
  bool done = false;
  int p;
  while(!done){
    std::cin >> p;
    if(p == 1)
      maximize();
    else if(p == 2)
      minimize();
    else
      done = true;
  }
}
