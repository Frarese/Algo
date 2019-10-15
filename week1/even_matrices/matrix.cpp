#include<iostream>

void matrix(int n)
{
	int M[n][n], even= 0, odd = 0, total = 0;

	for(int i = 0; i< n; i++)
		for(int j = 0; j <n; j++)
			std::cin >> M[i][j];

	for(int i = 0; i< n; i++)
		for(int j = 1; j<n; j++)
			M[i][j] += M[i][j-1];

	for(int j = 0; j< n; j++)
		for(int i = 1; i<n; i++)
			M[i][j] += M[i-1][j];

	for(int i1 = 0; i1< n; i1++)
		for(int i2 = i1; i2<n; i2++)
		{
			for(int j= 0; j< n; j++)
			{
				if(i1 != i2 && (M[i1][j] - M[i2][j]) % 2 == 0 )
					even++;
				if( i1 == i2 && M[i1][j]% 2 == 0)
					even++;
			}
			odd = n - even;
			total += (even*(even-1))/2 + (odd*(odd-1))/2 + even;
			even = 0; odd = 0;
		
		}

	std::cout << total << "\n";


}

int main()
{
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		matrix(n);
	}
	return 0;
}
