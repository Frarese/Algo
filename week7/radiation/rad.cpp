#include<iostream>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include<cmath>
#include<vector>

typedef std::vector<int> V;
typedef std::vector<V> Vv;
typedef CGAL::Gmpz ET;
typedef CGAL::Quadratic_program<long> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

void solve()
{
  int h,t; std::cin >> h >> t;
  Vv good(h,V(3)), bad(t, V(3));
  for(int i = 0; i< h; i++)
    std::cin >> good[i][0] >> good[i][1] >> good[i][2];
  for(int i = 0; i< t; i++)
      std::cin >> bad[i][0] >> bad[i][1] >> bad[i][2];

    bool done = false;
    int upper = 30, lower = 1;
    int q = upper;
    while(!done)
    {
      Program lp (CGAL::SMALLER, true, 0, false, 0);
      for(int i = 0; i< h; i++)
        {

        }
    }


}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int N; std::cin >> N;
  for(int i = 0; i< N; i++)
    solve();
}
