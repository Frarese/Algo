#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <stdexcept>
#include <climits>
#include <cstring>

using namespace std;

#define FF first
#define SS second
#define PB push_back
#define MP make_pair

const int MAXN =  1000 + 10;
const int IMPOSSIBLE = 1<<30;
int dp[MAXN][MAXN][3];
int a[MAXN];
int b[MAXN];

inline int cdp(int state,int a_i, int b_i)
{
    int& ans=dp[a_i][b_i][state];
    if(ans!=-1)return ans;
    if(state==0)return ans=min(cdp(1,a_i,b_i),cdp(2,a_i,b_i));
    if(state==1)
        return ans=min(cdp(0,a_i-1,b_i-1),cdp(1,a_i,b_i-1)) + a[a_i-1]*b[b_i-1];
    if(state==2)
        return ans=min(cdp(0,a_i-1,b_i-1),cdp(2,a_i-1,b_i)) + a[a_i-1]*b[b_i-1];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n_tests;
    scanf("%d", &n_tests);
    for(int i=0;i<MAXN;i++)for(int j=0;j<3;j++)dp[0][i][j]=dp[i][0][j]=IMPOSSIBLE;
    dp[0][0][0]=0;
    while(n_tests--)
    {
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){scanf("%d", &a[i]);a[i]--;}
        for(int i=0;i<n;i++){scanf("%d", &b[i]);b[i]--;}
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=-1;
        cout<<cdp(0,n,n)<<'\n';
    }
    return 0;
}
    
