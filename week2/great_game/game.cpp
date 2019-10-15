#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

typedef std::vector<int> v;
typedef std::vector<v> vv;

int game(int player, const vv &b, int pos, vv &M)
{
	if(pos == b.size() -1)
		return 0;
	if(M[player][pos] != -1)
		return M[player][pos];
	if(!player)
	{
		int result = INT_MAX;
		for(int i = 0; i< b[pos].size(); i++ )
			result = std::min (result, 1+ game(1,b, b[pos][i], M));

		M[player][pos] = result;
	
	}
	else
	{	int result = 0;
		for(int i = 0; i< b[pos].size(); i++ )
			result = std::max (result, 1+ game(0,b, b[pos][i], M));

		M[player][pos] = result;
	}
	
	return M[player][pos];

}


void setup(int n, int m)
{
	int r,b, u,w;
	std::cin >> r >> b;
	vv board(n+1, v(0));

	for(int i = 0; i< m; i++)
	{
		std::cin >> u >> w;
		board[u].push_back(w);
	}
	
	vv M(2, v(n+1,-1));	
	
	int P1 = game(0,board,r,M);
	int P2 = game(0,board,b,M);
	
	if(P1 < P2)
		std::cout << 0 << "\n";
	else if(P1 > P2)
		std::cout << 1 << "\n";
	else
		std::cout<< ((P1+1) % 2) << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n, m;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n >> m;
		setup(n,m);
	}
	return 0;
}
