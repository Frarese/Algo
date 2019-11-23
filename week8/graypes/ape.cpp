#include<iostream>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include<vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt Ks;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;
typedef Triangulation::Finite_faces_iterator  Face_iterator;

typedef K::Point_2 P;

void apes(int n)
{
  Triangulation t;
  std::vector<P> Vp;
  for(int i = 0; i < n; i++){
    int x,y; std::cin >> x >> y;
    Vp.push_back(P(x,y));
  }
  t.insert(Vp.begin(), Vp.end());
  K::FT min_squared_distance = std::numeric_limits<K::FT>::max();
  for(auto e = t.finite_edges_begin(); e != t.finite_edges_end(); ++e)
        min_squared_distance = std::min(min_squared_distance,t.segment(*e).squared_length());

  Ks::FT time = 50 * CGAL::sqrt(Ks::FT(min_squared_distance));
  std::cout << std::ceil(CGAL::to_double(time)) << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int N; std::cin >> N;
  while(N)
  {
    apes(N);
    std::cin >> N;
  }
  return N;
}
