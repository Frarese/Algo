#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

typedef std::vector<int> Vi;
typedef std::vector<Vi> VVi;

//must cover 0
//must take 1
//covered 2

int rec(int cur, int status, const VVi &r, const Vi &c,  VVi &mem)
{
	if(mem[status][cur] != -1)
		return mem[status][cur];

	int take = c[cur];
	for(int i = 0; i< r[cur].size(); i++ )
		take += rec(r[cur][i], 2,r,c,mem);

	if(status == 1)
	{
		mem[status][cur] = take;
		return mem[status][cur];
	}

	int take_child = 0;
	for(int i = 0; i< r[cur].size(); i++)
		take_child += rec(r[cur][i], 0,r,c,mem);

	int res = 0;
	int do_not_take = INT_MAX;
	for(int i = 0; i< r[cur].size(); i++)
	{
		res = take_child - rec(r[cur][i], 0,r,c,mem) + rec(r[cur][i], 1,r,c,mem);
		if(res < do_not_take)
			do_not_take = res;
	}

	if(status == 2)
		if(take_child < do_not_take)
		 do_not_take = take_child;

	mem[status][cur] = std::min(take, do_not_take);
	return mem[status][cur];
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

	VVi memo(3, Vi(n, -1));
	int result =  rec (0,0,roads, cost, memo);
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
