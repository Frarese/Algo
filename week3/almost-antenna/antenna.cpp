#include<iostream>
#include<CGAL/Exact_predicates_exact_constructions_kernel_with_sqrt.h>
#include<CGAL/Min_circle_2.h>
#include<CGAL/Min_circle_2_traits_2.h>
#include<vector>

typedef CGAL::Exact_predicates_exact_constructions_kernel_with_sqrt K;
typedef CGAL::Min_circle_2_traits_2<K> Traits;
typedef CGAL::Min_circle_2<Traits> Min_circle;
typedef K::Point_2 P;
typedef std::vector<P> Vp;

double ctd(const K::FT &x)
{
	double a = std::ceil(CGAL::to_double(x));
	while(a < x) a+=1;
	while(a-1 >= x ) a -= 1;
	return a;
}


void circle(int n)
{
	Vp p;
	long x,y;
	for(int i = 0; i< n; i++)
	{
		std::cin >> x >> y;
		p.push_back(P(x,y));
	}
	
	Min_circle mc(p.begin(), p.end(), true);
	Traits::Circle c = mc.circle();
	K::FT minR = c.squared_radius();
	for(int i = 0; i < n; i++)
	{
		if(mc.has_on_boundary(p[i]))
		{
			P temp = p[i];
			p.erase(p.begin()+i);
			Traits::Circle c = mc.circle();
			Min_circle mcx(p.begin(), p.end(), true);
			if(minR > mcx.circle().squared_radius())
				minR = mcx.circle().squared_radius();
			p.insert(p.begin()+i, temp);		
		}
	}


	K::FT r = CGAL::sqrt(minR);

	std::cout << ctd(r) << "\n";

}

int main()
{
	std::cout << std::setprecision(0) << std::fixed ;
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n ;
	while(n != 0)
	{
		circle(n);
		std::cin >> n;	
	}
	
	return 0;

}
