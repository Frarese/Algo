#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>

typedef std::vector<int> Vi;
typedef std::vector<Vi> VVi;
typedef std::map<Vi, int> Mi;

void split_list(int a, int b, Mi &mapx, const VVi &m, int k, Vi key)
{
	if(mapx.find(key) != mapx.end())
		mapx[key] = std::min(mapx[key], k);
	else
		mapx[key] = k;
	if(a > b)
		return;

	split_list(a+1,b,mapx,m,k,key);
	
	for(int i = 0; i< key.size(); i++)
		key[i] += m[a][i];

	split_list(a+1,b,mapx,m,k+1,key);
}


void light()
{
	int N,M; std::cin >> N >> M;
	Vi b(M);
	Vi b2(M);
	for(int i =0; i< M; i++)
	{
		std::cin >> b[i];
		b2[i] = b[i];
	}
	VVi museum(N, Vi(0));

	for(int i = 0; i< N; i++)
	{
		for(int j = 0; j< M; j++)
		{
			int on, off; std::cin >> on >> off;
			museum[i].push_back((off - on));
			b2[j] -= on;
		}
	};
	Vi v(M,0);
	Mi map1, map2;
	split_list(0, N/2, map1, museum, 0, v);
	split_list((N/2)+1, N-1, map2, museum, 0, v);

	int min_val = INT_MAX;
	for(auto it = map1.begin(); it != map1.end(); ++it)
	{
		Vi tmp(M);
		for(int i = 0; i< M; i++)
		{
			tmp[i] = b2[i] -  it->first[i];
		}
		if(map2.find(tmp) != map2.end())
			min_val = std::min(min_val, map2[tmp] + it->second);
	}	

	if(min_val != INT_MAX)
		std::cout << min_val << "\n";
	else
		std::cout << "impossible\n";
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T;
	std::cin >> T;
	for(int i =0;i < T; i++)
		light();
	return 0;
}
