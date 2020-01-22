#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

typedef std::vector<int> Vi;
typedef std::vector<Vi> Vvi;

int rec(int l, int r, Vi &a, Vi &b, Vvi &mem)
{
  if(mem[l][r] != -1)
    return mem[l][r];

  int Sa = 0, Sb = 0;
  int result = INT_MAX;
  for(int i = l; i> 0; i--)
  {
    Sa += a[i]; Sb = 0;
    for(int j = r; j > 0; j--)
    {
      Sb += b[j];
      result = std::min(result, rec(i-1, j-1,a,b,mem) + (Sa - (l-i+1))*(Sb - (r-j+1)));
    }
  }

  mem[l][r] = result;
  return result;
}


void solve()
{
  int n; std::cin >> n;
  Vi a(n+1), b(n+1);

  for(int i = 1; i< n+1; i++)
    std::cin>> a[i];

  for(int i = 1; i< n+1; i++)
    std::cin>> b[i];

  Vvi mem(n+1, Vi(n+1, -1));
  mem[0][0] = 0;

  for(int i= 1; i< n+1; i++)
  {
    mem[0][i] = 100*(n+1)*100*n;
    mem[i][0] = 100*(n+1)*100*n;
  }

  int result = rec(n,n,a,b,mem);
  std::cout << result << "\n";

}

int main()
{
  std::ios_base::sync_with_stdio(false);
  int t; std::cin >> t;
  while(t--)
    solve();
}
