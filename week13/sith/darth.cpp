#include <iostream>
#include <vector>
#include <algorithm>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <boost/pending/disjoint_sets.hpp>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;
typedef CGAL::Triangulation_vertex_base_with_info_2<int,K> Vb;
typedef CGAL::Triangulation_face_base_2<K> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb,Fb> Tds;
typedef CGAL::Delaunay_triangulation_2<K,Tds> DT;
typedef boost::disjoint_sets_with_storage<> Uf;

void solve()
{
  int n; long r; std::cin >> n >> r;
  std::vector<P> ps;

  for(int i = 0; i< n; i++)
  {
    int x,y; std::cin >> x >> y;
    ps.push_back(P(x,y));
  }

  DT t;
  std::vector<int> sizes(n,1), best;
  Uf uft(n);

  for(int i = n-1; i >= 0; i--)
  {
    auto vh = t.insert(ps[i]);
    vh->info() = i;
    auto vc = t.incident_vertices(vh);
    if(i== n-1)
      continue;

    do{
      if(t.is_infinite(vc))
        continue;
      if(CGAL::squared_distance(vh->point(), vc->point()) <= r*r)
      {
        int a = uft.find_set(i);
        int b = uft.find_set(vc->info());

        if(a == b)
          continue;
        else {
          int sumSize = sizes[a] + sizes[b];
          uft.union_set(i, vc->info());
          int c = uft.find_set(i);
          sizes[c] = sumSize;
        }
      }
    }while(++vc != t.incident_vertices(vh));

    best.push_back(std::min (i, sizes[uft.find_set(i)]));
    }

   std::cout << *std::max_element(best.begin(), best.end()) << "\n";

}


int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
