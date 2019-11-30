#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpq.h>
#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

typedef CGAL::Gmpq ET;

typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void suez()
{
  int n,m,h,w; std::cin >> n >> m >> h >> w;
  std::vector<std::pair<int,int>> red(n) , blue(m);
  std::vector<int> nr(n), nb(n);

  for (size_t i = 0; i < n; i++) {
    int x,y; std::cin >> x >> y;
    red[i] = std::make_pair(x,y);
  }
  for (size_t i = 0; i < m; i++) {
    int x,y; std::cin >> x >> y;
    blue[i] = std::make_pair(x,y);
  }

  Program lp (CGAL::SMALLER, true, 1, false, 0);

    int counter = 0;

    for (size_t i = 0; i < n; i++) {
      lp.set_c(i, -2*(h+w));
      for (size_t j = i+1; j < n; j++) {
          ET xdiff = std::abs(red[i].first - red[j].first);
          ET ydiff = std::abs(red[i].second - red[j].second);

          lp.set_a(i,counter,1);  lp.set_a(j,counter,1);
          lp.set_b(counter, 2 * std::max(xdiff/w, ydiff/h));
          counter++;
      }
    }

    for (size_t i = 0; i < n; i++) {
        ET best = 33554433;
        for (size_t j = 0; j < m; j++) {
          ET xdiff = std::abs(red[i].first - blue[j].first);
          ET ydiff = std::abs(red[i].second - blue[j].second);

          ET local_best = 2 * std::max(xdiff/w, ydiff/h) -1;
          best = std::min(local_best, best);

      }
      lp.set_a(i,counter,1);
      lp.set_b(counter, best);
      counter++;
    }
    Solution s = CGAL::solve_linear_program(lp, ET());
    std::cout << std::fixed;
    std::cout << std::setprecision(0) <<std::ceil(-1 * CGAL::to_double(s.objective_value())) << "\n";

}


int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  for (size_t i = 0; i < T; i++) {
    suez();
  }
}
