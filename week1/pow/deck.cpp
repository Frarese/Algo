#include<iostream>
#include<cmath>

void deck(int n, int k)
{
	int deck[n];

	for(int i = 0; i< n; i++)
	{
		std::cin >> deck[i];
		if(i > 0)
			deck[i] += deck[i-1];
	}
	
	int i = -1, j = 0, bestI, bestJ, bestK = -1;

	while(j< n && i <n)
	{
		int val;
		if( i < 0)
			val = deck[j];
		else
			val = deck[j] - deck[i];
		if(abs(val - k) < abs(bestK - k))
		{
			bestK = val;
			bestI = i;
			bestJ = j;
		}
		if(val < k)
			j++;
		else
			i++;
	}

	std::cout << bestI +1 << " " << bestJ << "\n";




}

int main()
{
	int T, n, k;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n >> k;
		deck(n,k);
	}
	return 0;
}
