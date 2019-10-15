#include<iostream>
#include<CGAL/Exact_predicates_exact_constructions_kernel.h>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Ray_2 R;
typedef K::Segment_2 S;
typedef K::Point_2 P;

void hit (int n)
{
	long x,y,a,b;
	S obs[n];
	R ray;
	std::cin >> x >> y >> a >> b;
	ray = R(P(x,y), P(a,b));
	for(int i = 0; i< n; i++)
	{
		std::cin >> x >> y >> a >> b;
		obs[i] = S(P(x,y), P(a,b));
	}
	bool meet = false;
	for(int i = 0; i< n && !meet; i++)
	{
		if(CGAL::do_intersect(ray, obs[i]))
			meet = true;
	}

	if(meet)
		std::cout << "yes" << "\n";
	else
		std::cout << "no" << "\n";
	
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	while(n!= 0)
	{
		hit(n);
		std::cin >> n;
	}
	return 0;

}
