#include<iostream>
#include<cmath>
#include<vector>

typedef std::vector<int> v;
typedef std::vector<v> vv;

int game2(int a, int b, vv &M1, vv &M2, const v &c);

int game1(int a, int b,vv &M1, vv &M2,const  v &c){
	if(a == b)
		return c[a];

	if(M1[a][b] != -1)
		return M1[a][b];
	else
	{
		M1[a][b] = std::max (c[a]+game2(a+1, b, M1,M2,c), c[b]+game2(a,b-1,M1,M2,c));
	}
	return M1[a][b];
}

int game2(int a, int b, vv &M1, vv &M2,const v &c)
{
	if(a == b)
		return 0;

	if(M2[a][b] != -1)
		return M2[a][b];
	else
	{
		M2[a][b] = std::min (game1(a+1, b, M1,M2,c), game1(a,b-1,M1,M2,c));
	}
	return M2[a][b];
}


void coins(int n)
{

	v coins;
	for(int i = 0; i< n; i++){
		int r;
		std::cin >> r;
		coins.push_back(r);
		
	}

	vv M1(n, v(n, -1));
	vv M2(n, v(n, -1));
	int result = std::max(coins[0]+game2(1,n-1,M1,M2,coins),coins[n-1]+game2(0,n-2,M1,M2, coins));
		
	std::cout << result << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n;
	std::cin >> T;
	
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		if(n == 1)
		{
			int temp;
			std::cin >> temp;
			std::cout << temp << "\n";
		}
		else
			coins(n);
	}
	return 0;
}
