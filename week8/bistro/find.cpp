#include<iostream>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include<vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Finite_faces_iterator  Face_iterator;
typedef K::Point_2 P;

void find(int n)
{
  std::vector<P> res;
  for(int i = 0; i< n; i++)
  {
    int x,y; std::cin >> x >> y;
    res.push_back(P(x,y));
  }
  Triangulation t;
  t.insert(res.begin(), res.end());
  int m; std::cin >> m;
  for(int i = 0; i < m; i++)
  {
    int x,y; std::cin >> x >> y;
    P point(x,y);
    std::cout << std::fixed;
    std::cout << std::setprecision(0) << CGAL::to_double(CGAL::squared_distance(point, t.nearest_vertex(point)->point())) << "\n";
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int N; std::cin >> N;
  while(N)
  {
    find(N);
    std::cin >> N;
  }
  return N;
}
