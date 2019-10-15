#include<iostream>
#include<cmath>
#include<vector>

typedef std::vector<int>  Vi;
typedef std::vector<Vi> VVi;

int game(int p, int c[], int a, int b, const int k, const int m, VVi &mem)
{
	if (p == k){
		if(a == b)
			return c[a];
		if(mem[a][b] == -1)
			mem[a][b] = std::max(c[a] + game(((p+1) %m ), c, a+1, b,k,m, mem), c[b] + game(((p+1) %m ), c, a, b-1,k,m, mem));
		return mem[a][b];
	}
	else{
		if(a == b)
			return 0;
		if(mem[a][b] == -1)
			mem[a][b] = std::min(game(((p+1) %m ), c, a+1, b,k,m, mem),game(((p+1) %m ), c, a, b-1,k,m, mem));
		return mem[a][b];
	}
}

void russia(int n, int  m, int k)
{
	int coins[n];
	VVi mem(n, Vi(n, -1));

	for(int j  = 0; j < n ; j++){
		int temp;
		std::cin >> temp;
		coins[j] = temp;
	}
	int result = game(0,coins, 0, n-1, k, m, mem);

	std::cout << result << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T ,n, m, k;
	std::cin >> T;
	for(int i = 0; i< T; i++){
		std::cin >> n >> m >> k;
		russia(n,m,k);
	}
	return 0;
}
