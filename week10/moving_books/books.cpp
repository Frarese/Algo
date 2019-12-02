#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void books()
{
  int n, m; std::cin >> n >> m;
  std::vector<int> s(n), w(m);
  std::multiset<int, std::greater<int>> ws;
  for (size_t i = 0; i < n; i++)
    std::cin >> s[i];
  for (size_t i = 0; i < m; i++){
    std::cin >> w[i];
    ws.insert(w[i]);
  }

  std::sort(s.begin(), s.end(), std::greater<int>());
  std::sort(w.begin(), w.end(), std::greater<int>());

  if(s[0]< w[0])
  {
    std::cout << "impossible\n";
    return;
  }
  int time = 0;
  while(!ws.empty()){
    for(int i = 0; i< n; i++){
      auto b = ws.lower_bound(s[i]);
              if (b != ws.end()) {
                  ws.erase(b);
              } else {
                  break;
              }

    }
      time += 3;
  }
  std::cout << time-1 << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  while (T--) {
    books();
  }
}
