#include<iostream>
#include<vector>
#include<algorithm>


typedef std::vector<std::pair<int,int>> Vi;

void boats(int n)
{
	int l, p;
	Vi places(n);
	for(int i = 0; i< n; i++)
	{
		std::cin >> l >> p;
		places[i] = std::make_pair(p,l);
	}
	std::sort(places.begin(), places.end());
	
	bool over = false;
	int count = 1;
	int pos = places[0].first;
	int prepos = 0;
	for(int i = 1; i< n; i++)
	{
		if(places[i].first >= pos)
		{
			prepos = pos;
			if(places[i].first - pos > places[i].second)
				pos = places[i].first;
			else
				pos += places[i].second;
			count++;
		}
		else if(places[i].first - prepos > places[i].second)
		{
			pos = places[i].first;
		}
		else if(prepos + places[i].second < pos)
			pos = places[i].second + prepos;
	}

	std::cout << count << "\n";
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T,n ;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		boats(n);
	}
	return 0;
}
