#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

typedef std::vector<int> Vi;
typedef std::vector<Vi> VVi;

int rec(int c, int col, VVi &mem, VVi &r, Vi &C)
{
	if(r[c].size() == 0)
		return C[c]*col;


	if(mem[col][c] != -1)
		return mem[col][c];

	int result = 0;
	if(col)
	{
		for(int i = 0; i< r[c].size(); ++i)
				result += std::min(rec(r[c][i],0 ,mem,r,C), rec(r[c][i],1,mem,r,C));
		mem[1][c] = result + C[c];

		return mem[1][c];
	}
	else
	{
		int bestChild;
		int bestCost = INT_MAX;
		bool leaf;
		for(int i = 0; i< r[c].size(); ++i)
		{
			int v = r[c][i];
			if(r[v].size() == 0)
				leaf = true;
		}
		if(leaf)
			for(int i = 0; i< r[c].size(); ++i)
			{	
			
				int v = r[c][i];
				if(r[v].size()== 0)
					result += rec(v,1,mem,r,C);
				else
					result += std::min(rec(v,0 ,mem,r,C), rec(v,1,mem,r,C));
			}
		else
		{
			for(int i = 0; i< r[c].size(); ++i)
			{
				int v = r[c][i];
				int cost = rec(v,1,mem,r,C);

				if(cost < bestCost)
				{
					bestChild = v;
					bestCost = cost;
				}
			}
			result += bestCost;
			for(int i = 0; i< r[c].size(); ++i)
			{
				int v = r[c][i];
				if(v != bestChild)
				{
					result += std::min(rec(v,0 ,mem,r,C), rec(v,1,mem,r,C));
				}
			}
		
		}
		mem[0][c] = result;
		
		return mem[0][c];
	}
}



void chariot(int n)
{
	int a,b;
	Vi cost(n);
	VVi roads(n, Vi(0));
	for(int i = 0; i< n-1; ++i)
	{
		std::cin >> a >> b;
		roads[a].push_back(b);
	}

	for(int i = 0; i< n; i++)
		std::cin >> cost[i];

	VVi memo(2, Vi(n, -1));
	int result = std::min(rec(0,0 , memo, roads, cost), rec(0,1,memo,roads,cost));
		
	std::cout << result << "\n";
}

int main()
{
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; ++i)
	{
		std::cin >> n;
		chariot(n);
	}

	return 0;
}
