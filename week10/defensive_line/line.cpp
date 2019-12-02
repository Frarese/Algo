#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

typedef std::vector<std::pair<int,int>> Vp;
typedef std::vector<std::vector<int>>  Vv;
typedef std::vector<int>  Vi;

int rec2(Vi &mem2,const  Vi &M, int lo, int up)
{
  if (lo == up - 1) {
       return (M[lo] == -1) ? -1 : 1;
   }

   if (mem2[lo] != -2) {
       return mem2[lo];
   }

   int curr = M[lo] - lo + 1;
    int rec = rec2(mem2, M, lo + 1, up);
    mem2[lo] = (curr > rec) ? curr:rec;
    return mem2[lo];
}

int rec(Vv &mem, Vi &mem2, const Vi &M, int att, int lo, int up )
{
  if(lo == up )
     return -1;

   if (mem[att - 1][lo] != -2)
      return mem[att - 1][lo];

  if (att == 1) {
              int max_attack = rec2(mem2, M, lo, up);
              mem[att - 1][lo] = max_attack;
              return max_attack;
          }

      int max_attack = -1;
    for (int j = lo; j < up - 1; ++j) {
        int curr_attack;
        if (M[j] == -1) {
            curr_attack = -1;
        } else {
            int rec_max = rec(mem, mem2, M, att - 1, M[j] + 1, up);
            if (rec_max == -1) {
                curr_attack = -1;
            } else {
                curr_attack = M[j] - j + 1 + rec_max;
            }
        }
        if (curr_attack > max_attack) {
            max_attack = curr_attack;
        }
    }
    mem[att - 1][lo] = max_attack;
    return max_attack;
}
void line()
{
  int n, m, k; std::cin >> n >> m >> k;
  Vi def(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> def[i];
    }

  std::vector<int> M(n, -1);
  int i = 0;
  int j = 0;
  int sum = def[i];
  int countK = 0;
  while (i < n && j < n) {
      if (sum <= k) {
          if (sum == k) {
              M[i] = j;
              countK++;
          }

          j++;
          sum += def[j];
      } else {
          sum -= def[i];
          i++;
      }
  }
  if (countK < m) {
       std::cout << "fail" << std::endl;
       return;
   }
  Vv mem(m, Vi(n,-2));
  Vi mem2(n,-2);
  int result = rec(mem, mem2, M, m, 0, n);

  if (result < 0) {
        std::cout << "fail" << std::endl;
    } else {
        std::cout << result << std::endl;
    }
    return;

}


int main()
{
  std::ios_base::sync_with_stdio(false);
  int T; std::cin >> T;
  while(T--)
    line();
}
