#include<iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include<vector>
#include<boost/pending/disjoint_sets.hpp>


typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Triangulation_vertex_base_with_info_2<K::FT,K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds>  Triangulation;
typedef Triangulation::Finite_faces_iterator  Face_iterator;
typedef K::Point_2 P;
typedef boost::disjoint_sets_with_storage<>                  Uf;

void solve()
{
  int n,m,r; std::cin >> n >> m >> r;
  std::vector<P> points;
  std::vector<std::pair<P,P>> queries;
  for (size_t i = 0; i < n; i++) {
    int x,y;
    std::cin >> x >> y;
    points.push_back(P(x,y));
  }
  for (size_t i = 0; i < m; i++) {
    int x,y, w,z;
    std::cin >> x >> y >> w >> z;
    queries.push_back(std::make_pair(P(x,y), P(w,z)));
  }

  int max_dist = r*r;

  Triangulation t;
  t.insert(points.begin(), points.end());

  bool compliant = true;

  int count = 0;
  for(auto v = t.finite_vertices_begin(); v != t.finite_vertices_end(); ++v)
  {
    v->info() = count;
    count++;
  }

  if(n>2)
    for(Face_iterator f = t.finite_faces_begin(); f != t.finite_faces_end(); ++f)
    {
      if( CGAL::squared_distance(f->vertex(0)->point(), f->vertex(1)->point()) < max_dist &&
          CGAL::squared_distance(f->vertex(1)->point(), f->vertex(2)->point()) < max_dist &&
            CGAL::squared_distance(f->vertex(2)->point(), f->vertex(0)->point()) < max_dist)
                compliant = false;
      }

  if(!compliant){
    for (size_t i = 0; i < m; i++) {
      std::cout << "n";
    }
    std::cout << "\n";
    return;
  }

    Uf ufp(n);
    for(auto e = t.finite_edges_begin(); e != t.finite_edges_end(); ++e)
    {
      if(t.segment(e).squared_length() < max_dist)
        ufp.union_set(e->first->vertex((e->second+1)%3)->info(), e->first->vertex((e->second+2)%3)->info());
    }

    for (size_t i = 0; i < m; i++) {
      auto v0 = t.nearest_vertex(queries[i].first);
      auto v1 = t.nearest_vertex(queries[i].second);
      K::FT d = std::max(CGAL::squared_distance(queries[i].first, v0->point()),
                                 CGAL::squared_distance(queries[i].second, v1->point()));

      if (d < max_dist && ufp.find_set(v0->info()) == ufp.find_set(v1->info()))
        std::cout << "y";
      else
        std::cout << "n";
    }
    std::cout << "\n";


}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
