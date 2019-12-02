#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_vertex_base_with_info_2.h>
#include <CGAL/Point_set_2.h>
#include <iostream>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 P;
typedef CGAL::Triangulation_vertex_base_with_info_2<int, K> Vb;
typedef CGAL::Triangulation_data_structure_2<Vb> Tds;
typedef CGAL::Point_set_2<K, Tds> PSet;
typedef CGAL::Point_set_2<K, Tds>::Vertex_handle Vertex_handle;

void lux()
{
  int m,n; std::cin >> m >> n;
  std::vector<std::pair<P,int>> part(m), light(n);

  for (size_t i = 0; i < m; i++) {
    int x,y,r; std::cin >> x >> y >> r;
    part[i] = std::make_pair(P(x,y),r);
  }

  int h; std::cin >> h;

  for (size_t i = 0; i < n; i++) {
    int x,y; std::cin >> x >> y;
    light[i] = std::make_pair(P(x,y),i);
  }

  PSet t(light.begin(), light.end());

  std::vector<int> first_hit(m, n+1);
  int last_light = -1;

  for (size_t i = 0; i < m; i++) {
      Vertex_handle near = t.nearest_neighbor(part[i].first);

      double max_dist = std::pow(part[i].second + h, 2);

      if(max_dist <= CGAL::squared_distance(part[i].first, near->point()))
        continue;

      for(int j = 0; j< n; j++)
      {
          if(max_dist > CGAL::squared_distance(part[i].first, light[j].first))
          {
            last_light = std::max(light[j].second,last_light);
            first_hit[i] = light[j].second;
            break;
          }
      }
  }
  std::vector<int> winners;
    for(int i = 0; i < m; i++) {
      if(first_hit[i] == n+1) {
        winners.push_back(i);
      }
    }

  if(winners.size() <= 0) {
    for(int i = 0; i < m; i++) {
      if(first_hit[i] == last_light) {
        winners.push_back(i);
      }
    }
  }

  std::sort(winners.begin(), winners.end());
    for(int i = 0; i < winners.size(); i++) {
        std::cout << winners[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  while(T--)
    lux();
}
