#include<iostream>
#include<cmath>

void domino(int n)
{
	int d[n], fallen = 0, dom= 0;
	for(int i = 0; i< n; i++)
		std::cin >> d[i];
	
	fallen++;
	dom = d[0];

	for(int i = 1; i< n; i++)
	{
		dom--;
//		std::cout << dom << "\n";
		if(dom > 0)
		{
			fallen++;
			dom = std::max(dom, d[i]);
		}
	}
	std::cout << fallen << "\n";

}

int main()
{
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		domino(n);
	}
	return 0;
}
