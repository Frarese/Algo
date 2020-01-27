#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include <cmath>
// choose exact type for solver (CGAL::Gmpz or CGAL::Gmpq)
typedef CGAL::Gmpz ET;

// program and solution types
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void roman()
{
  long x,y,n; std::cin >> x >> y >> n;
  Program lp (CGAL::SMALLER, false, 0, false, 0);

  const int X = 0, Y = 1, R = 2;
  for(int i = 0; i< n; i++)
  {
    long a,b,c,v; std::cin >> a >> b >> c >> v;
    long s = (long)std::sqrt(a*a + b*b);

    if(a*x+b*y+c > 0){
     // lp.set_a(X,i*2 +1,-a); lp.set_a(Y,i*2 +1,-b); lp.set_b(i*2 + 1, c);
      lp.set_a(X,i*2,-a); lp.set_a(Y,i*2,-b); lp.set_a(R, i*2, s*v); lp.set_b(i*2,c);
  }
    else if(a*x+b*y+c < 0){
     // lp.set_a(X,i*2 +1,a); lp.set_a(Y,i*2 +1,b); lp.set_b(i*2 + 1, -c);
      lp.set_a(X,i*2,a); lp.set_a(Y,i*2,b); lp.set_a(R, i*2, s*v); lp.set_b(i*2, -c);
    }
  }
    lp.set_l(R,true,0);
    lp.set_c(R, -1);

    Solution s = CGAL::solve_linear_program(lp, ET());
    std::cout << std::fixed << std::setprecision(0);
    std::cout << std::floor( CGAL::to_double(-s.objective_value())) << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while (t--) {
    roman();
  }
}
