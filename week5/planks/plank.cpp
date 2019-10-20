#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

typedef std::vector<int> Vi;
typedef std::map<Vi,int> Mi;

void split_list(int a, int b, Mi &mapx, int side, Vi v, const Vi &l)
{
	if(a > b)
	{
		if(mapx.find(v) !=  mapx.end())
			mapx[v] += 1;
		else
			mapx[v] = 1;
		return;
	}	

	for(int i = 0; i< 4; i++)
	{
		Vi tmp(v.begin(), v.end());
		if(v[i] + l[a] <= side)
		{
			tmp[i] += l[a];
			split_list(a+1,b,mapx,side,tmp,l);
		}
	}
}


void plank()
{
	int n, sum = 0; std::cin >> n;
	Vi l(n);
	for(int i = 0; i< n; i++)
	{
		std::cin >> l[i];
		sum+= l[i];
	}
	
	if((sum %4) != 0 || *std::max_element(l.begin(), l.end()) > (sum/4))
	{
		std::cout << 0 <<"\n";
		return;
	}

	Mi map1, map2;
	Vi v(4,0);
	split_list(0, n/2, map1, sum/4, v, l);
	split_list((n/2)+1, n-1, map2, sum/4, v, l);

	int total = 0;
	for(auto it = map1.begin(); it != map1.end(); ++it)
	{
		Vi tmp(4,sum/4);
		for(int i = 0; i< 4; i++)
			tmp[i] -= it->first[i];

		if(map2.find(tmp) != map2.end())
			total += map2[tmp]*it->second;
	}
	std::cout << (total/24) << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);

	int T; std::cin >> T;
	for(int i = 0; i< T; i++)
		plank();
	return 0;
}
