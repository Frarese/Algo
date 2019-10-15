#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

#define D 100

void beach(int n)
{
	std::vector<int> beach;
	for(int i = 0; i< n; i++){
		int tmp;
		std::cin >> tmp;
		beach.push_back(tmp);
	}
	std::sort(beach.begin(), beach.end());

	int i = 0, j = 0, maxD = D, maxC = 0;
       	std::vector<int> coor;

	while(i< beach.size() && j < beach.size())
	{
		int dist = beach[j] - beach[i];
		int d;
		if(dist % 2 == 0)
			d = dist/2;
		else
			d = (dist+1)/2;

		int cli = j-i+1;
		if(d <= D)
		{
			if(cli == maxC && d <= maxD)
			{
				if(d < maxD)
				{
					coor.clear();
					maxD = d;
				}
				if((beach[j] +beach[i]) >= 0){
					coor.push_back((beach[j] + beach[i]) /2);
					if(dist % 2 == 1)
						coor.push_back(((beach[j] + beach[i]) /2) +1);
				}
				else{
					if(dist % 2 == 1)
						coor.push_back(((beach[j] + beach[i]) /2) -1);
					coor.push_back(((beach[j] + beach[i]) /2));
				}
				
			}
			else if(cli > maxC)
			{
				maxC = cli;
				coor.clear();
				maxD = d;
				if((beach[j] +beach[i]) >= 0){
					coor.push_back((beach[j] + beach[i]) /2);
					if(dist % 2 == 1)
						coor.push_back(((beach[j] + beach[i]) /2) +1);
				}
				else{
					if(dist % 2 == 1)
						coor.push_back(((beach[j] + beach[i]) /2) -1);
					coor.push_back(((beach[j] + beach[i]) /2));
				}
			}

			j++;
		}
		else
			i++;
	}	
	
	std::cout << maxC << " " << maxD << "\n";
	for(int k = 0; k < coor.size(); k++){
		std::cout << coor[k];
		if(k < coor.size() -1)
			std::cout << " ";
	}
	std::cout << "\n";
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	int T, n;
	std::cin >> T;
	for(int i = 0; i< T; i++)
	{
		std::cin >> n;
		beach(n);
	}
	return 0;
}
