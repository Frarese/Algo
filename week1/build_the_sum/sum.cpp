#include<iostream>

void sum(int n)
{
	int sum = 0, t;
	for(int i = 0; i< n; i++)
	{
		std::cin >> t;
		sum += t;
	}

	std::cout << sum << "\n";
}


int main()
{
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		sum(n);
	}
	return 0;
}
