#include<iostream>

void even(int n)
{
	int array[n];
	int even = 0, odd;
	for(int i =0 ; i< n; i++)
	{
		std::cin >> array[i];
		if(i>0)
			array[i] += array[i-1];

		if(array[i]%2 == 0)
			even++;
	}
	odd = n - even;
	int res = (even* (even -1))/2 + (odd* (odd -1))/2 + even;
	std::cout << res << "\n";

}


int main()
{
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		even(n);
	}
	return 0;
}
