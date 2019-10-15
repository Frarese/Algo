#include<iostream>
#include<CGAL/Exact_predicates_exact_constructions_kernel.h>
#include<climits>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Ray_2 R;
typedef K::Segment_2 S;
typedef K::Point_2 P;

double f_t_d(const K::FT &x){
	double a = std::floor(CGAL::to_double(x));
	while(a > x) a -= 1;
	while(a+1 <= x) a += 1;
	return a;
}

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
	std::random_shuffle(obs, obs +n);
	bool meet = false;
	K::FT dist;
	S seg(ray.source(), ray.source());
	int i;
	for(i = 0; i< n && !meet; ++i){
		if(CGAL::do_intersect(ray, obs[i])){
			auto o = CGAL::intersection(ray,obs[i]);
			if(const P* op = boost::get<P>(&*o)){
					seg = S(seg.source(), *op);
					meet = true;
			}
			else if(const S* op = boost::get<S>(&*o)){
					seg = S(seg.source(), op->source());
					meet = true;
					if(CGAL::has_smaller_distance_to_point(ray.source(), op->target(), seg.target()))
						seg = S(seg.source(), op->target());
			}
		}
	}
	
	for(; i< n; ++i)
	{
		if(CGAL::do_intersect(seg, obs[i])){
			auto o = CGAL::intersection(seg,obs[i]);
			if(const P* op = boost::get<P>(&*o)){
					seg = S(seg.source(), *op);
			}
			else if(const S* op = boost::get<S>(&*o)){
					seg = S(seg.source(), op->source());
					if(CGAL::has_smaller_distance_to_point(ray.source(), op->target(), seg.target()))
						seg = S(seg.source(), op->target());
			}
		}
	}


	if(meet)
		std::cout << f_t_d(seg.target().x()) <<" " << f_t_d(seg.target().y()) << "\n";
	else
		std::cout << "no" << "\n";
	
}

int main()
{
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(0);	
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
