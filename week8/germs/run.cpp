#include<iostream>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include<vector>
#include<algorithm>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt Ks;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;

typedef K::Point_2 P;

void apes(int n)
{
  int l,b,r,t; std::cin >> l >> b >> r >> t;
  Triangulation tr;
  std::vector<P> Vp;
  for(int i = 0; i < n; i++){
    int x,y; std::cin >> x >> y;
    Vp.push_back(P(x,y));
  }

  tr.insert(Vp.begin(), Vp.end());

  std::vector<K::FT> min_squared;
  for(auto v = tr.finite_vertices_begin(); v != tr.finite_vertices_end(); v++)
  {
    K::FT min_squared_distance = std::numeric_limits<K::FT>::max();
    P const &g = v->point();
    K::FT min_h_distance = std::min(g.x() - l, r - g.x() );
    K::FT min_v_distance = std::min(g.y() - b, t - g.y() );
    K::FT best = std::min(min_h_distance,min_v_distance);

    if(n>1){
      Triangulation::Edge_circulator c = tr.incident_edges(v);
      do{
          if(!(tr.is_infinite(c))) {
            min_squared_distance = std::min(min_squared_distance, tr.segment(*c).squared_length());
         }
      }while (++c != tr.incident_edges(v));
    }
    min_squared_distance = std::min(min_squared_distance, 4*best*best);
    min_squared.push_back(min_squared_distance);
  }
  sort(min_squared.begin(), min_squared.end());

  std::cout << std::fixed;
  std::cout << std::setprecision(0)<< std::ceil(CGAL::to_double(CGAL::sqrt((CGAL::sqrt(min_squared[0]) -1)/2))) << " "
  << std::ceil(CGAL::to_double(CGAL::sqrt((CGAL::sqrt(min_squared[n/2]) -1)/2))) << " "
  << std::ceil(CGAL::to_double(CGAL::sqrt((CGAL::sqrt(min_squared[n-1]) -1)/2))) << "\n";
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
