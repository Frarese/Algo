#include<iostream>
#include<vector>
#include<algorithm>

typedef std::vector<bool> Vb;
typedef std::vector<std::pair<int,int>> Vp;

int num_des(int a, int n, Vb &d)
{
	if(!d[a])
	{
		d[a] = true;
		if((2*a) +1 < n)
			return num_des((2*a) +1, n, d) + num_des((2*a) +2, n,d) +1;
		else 
			return 1;
	}
	else
		return 0;
}


void balls()
{
	int n; std::cin >> n;
	Vb deact(n, false);
	Vp balls(n);

	for(int i = 0;i< n; i++){
		int time; std::cin >> time;
		balls[i] = std::make_pair(time,i);
	}
	std::sort(balls.begin(), balls.end());
	
	int t = 0;

	for(int i = 0; i< n; i++)
	{
		int u = balls[i].second;
		int tiktok = balls[i].first;
		if(!deact[u])
		{       
			int deact_time = num_des(u,n,deact);
		//	std::cout << u << " " << deact_time << "\n";
			if(deact_time <= tiktok -t )
				t += deact_time;
			else
			{
				std::cout << "no\n";
				return;
			}
		}
		
	}
	std::cout << "yes\n";

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int T; std::cin >> T;
	for(size_t i = 0; i< T; i++)
		balls();
	return 0;
}
