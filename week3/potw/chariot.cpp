#include<iostream>
#include<vector>
#include<cmath>
#include<climits>

typedef std::vector<int> Vi;
typedef std::vector<Vi> VVi;



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
	int result = 0;		
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
