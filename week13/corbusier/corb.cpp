#include<iostream>
#include<vector>

typedef std::vector<std::vector<bool>> Vvb;
typedef std::vector<int> Vi;

void solve()
{
	int n,i,k;
	std::cin >> n >> i >> k;
	Vi h(n);
	Vvb reach(n,std::vector<bool>(k,false));
	
	for(int i = 0; i< n; i++)
		std::cin >> h[i];

	reach[0][h[0]%k] = true;

	for(int i = 1; i< n; i++)
	{
		reach[i][h[i]%k] = true;

		for(int j = 0; j< k; j++)
			if(reach[i-1][j])
			{
				reach[i][j] = true;
				reach[i][(j+ h[i]) %k] = true;
			}
	}
	
	if(reach[n-1][i])
		std::cout << "yes\n";
	else
		std::cout << "no\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int T; std::cin >> T;
	while(T--)
	{
		solve();
	}
}
