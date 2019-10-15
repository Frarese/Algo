#include<iostream>
#include<vector>
#include<algorithm>
#include<CGAL/Exact_predicates_exact_constructions_kernel.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 P;
typedef K::Line_2 L;
typedef K::Direction_2 D;

typedef std::pair<long,long> Pll;
typedef std::pair<long,int> Pli;
typedef std::vector<std::pair<Pli,Pll>> Vpp;
typedef std::vector<std::pair<int,D>> Vid;

void rider(int n)
{
  long y0, x1, y1;
  Vid winners;
  Vpp points;
  for(int i = 0; i< n; i++)
  {
    std::cin >> y0 >> x1 >> y1;
    points.push_back(std::make_pair(std::make_pair(y0,i), std::make_pair(x1,y1)));
  }
  std::sort(points.begin(), points.end());
  std::reverse(points.begin(), points.end());

  for(int i = 0; i< n; i++)
  {
    bool test = true;
    L temp(P(0,points[i].first.first),P(points[i].second.first,points[i].second.second));
    int val = points[i].first.second;
  gohere:  if(winners.empty())
      winners.push_back(std::make_pair(val,D(temp)));
    else
    {
      D dir(temp);
      K::RT dx = dir.dx(), dy = dir.dy();
      if(dy >= 0 && winners.back().second.dy() >= 0)
      {
        if(dy*winners.back().second.dx() <= dx*winners.back().second.dy() ){
          winners.push_back(std::make_pair(val,dir));
        }
      }
      else if(dy <= 0 && winners.back().second.dy() <= 0)
      {
        if(dy*winners.back().second.dx() > dx*winners.back().second.dy() ){
          winners.pop_back();
          goto gohere;
          //winners.push_back(std::make_pair(val,dir));
        }

        else if(dy*winners.back().second.dx() <= dx*winners.back().second.dy())
          winners.push_back(std::make_pair(val,dir));

        }
        else if(dy >= 0 && winners.back().second.dy() <= 0)
        {
          if(abs(dy*winners.back().second.dx()) <= abs(dx*winners.back().second.dy())){
            winners.pop_back();
            goto gohere;
          }
        }
        else
          winners.push_back(std::make_pair(val, dir));
      }
  }
  std::vector<int> vals;
  for( int i = 0; i< winners.size(); i++)
  {
    vals.push_back(winners[i].first);
  }
  std::sort(vals.begin(), vals.end());

  for (size_t i = 0; i < vals.size(); i++) {
    std::cout << vals[i] << " ";
  }
  std::cout << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T, n;
  std::cin >> T;
  for (int i = 0 ; i < T ; i++) {
    std::cin >> n;
    rider(n);
  }
  return 0;
}
