#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

typedef std::vector<int> Vi;
typedef std::vector<Vi> Vvi;
typedef std::vector<Vvi> Vii;

#define N 1000+2
#define top 100*100*N*N+1

Vi a(N), b(N);
Vii mem(N, Vvi(N, Vi(3,-1)));


inline int rec(int l, int r, int status)
{
  if(mem[l][r][status] != -1)
    return mem[l][r][status];

  if(status == 0)
	  return mem[l][r][status] = std::min(rec(l,r,1), rec(l,r,2));
  if(status == 1)
	  return mem[l][r][status] = std::min(rec(l-1,r-1,0), rec(l-1,r,1)) + a[l]*b[r];
  if(status == 2)
	  return mem[l][r][status] = std::min(rec(l-1,r-1,0), rec(l,r-1,2)) + a[l]*b[r];
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int t; std::cin >> t;

  
  for(int i= 0; i< N; i++)
  {
    for(int j = 0; j<3; j++)
    { 
    	mem[0][i][j] = mem[i][0][j] = top;
    }
  }

  mem[0][0][0] = 0;
  while(t--)
  {	
    int n; std::cin >> n;


  for(int i = 1; i< n+1; i++)
  {
    std::cin>> a[i];
    a[i]--;
  }

  for(int i = 1; i< n+1; i++)
  {
    std::cin>> b[i];
    b[i]--;
  }

  for(int i = 1; i< n +1; i++)
	  for(int j = 1; j< n+1; j++)
		  mem[i][j][0] =  mem[i][j][1] = mem[i][j][2] = -1;


  std::cout << rec(n,n,0) << "\n";

  }
}
