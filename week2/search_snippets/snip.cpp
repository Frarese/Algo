#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

void snip(int n)
{
	int m[n];
	std::vector< std::pair<int,int> > text;

	for(int i = 0; i< n; i++)
		std::cin >> m[i];

	for(int i = 0; i< n; i++)
		for(int j = 0; j < m[i]; j++)
		{
			int c;
			std::cin >> c;
			text.push_back(std::make_pair(c,i));
		}
	std::sort(text.begin(), text.end());	
	
	int occ[n] = {0}, i = 0, j = 0, unique = 1, r = INT_MAX;
	occ[text[i].second]++;

	while(i < text.size() && j < text.size())
	{
		if(unique == n){
			r = std::min(r, text[j].first - text[i].first +1);
			occ[text[i].second]--;
			if(occ [text[i].second] == 0)
				unique--;
			i++;
		}
		else{
			j++;
			occ[text[j].second]++;
			if(occ[text[j].second] == 1)
				unique++;
		}
	}	

	std::cout << r << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		snip(n);
	}
	return 0;
}
