#include<iostream>
#include<vector>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Delaunay_triangulation_2.h>
#include<CGAL/QP_models.h>
#include<CGAL/QP_functions.h>
#include<CGAL/Gmpq.h>

typedef CGAL::Gmpq ET;
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Triangulation;
typedef K::Point_2 P;

void solve()
{
	int a,s,b; std::cin >> a >> s >> b;
	int e; std::cin >> e;
	std::vector<std::pair<P,int>> roid;
	for(int i = 0; i< a; ++i)
	{
		int x,y,d; std::cin >> x >> y >> d;
		roid.push_back(std::make_pair(P(x,y),d));
	}
	std::vector<std::pair<P,double>> targets;
	for(int i = 0; i< s; ++i)
	{
		int x,y; std::cin >> x >> y;
		targets.push_back(std::make_pair(P(x,y), 1048576.0));
	}
	std::vector<P> fetts;
	for(int i = 0; i< b; ++i)
	{
		int x,y; std::cin >> x >> y;
		fetts.push_back(P(x,y));
	}

	Triangulation t;
	t.insert(fetts.begin(),fetts.end());

	Program lp(CGAL::LARGER, true, 0, false, 0);
	
	for(int i = 0; i < s; ++i) {
		if (b > 0) {
			Triangulation::Vertex_handle va = t.nearest_vertex(targets[i].first);
		       	targets[i].second = CGAL::squared_distance(targets[i].first, va->point());
	   	}
	   lp.set_c(i, 1);
     	}

	for (int i = 0; i < a; ++i) {
		for (int j = 0; j < s; ++j) {
		 	K::FT sqdist = CGAL::squared_distance(roid[i].first, targets[j].first);
		 	if (sqdist < targets[j].second) {
		       		if (sqdist > 0)
			     		lp.set_a(j, i, 1 / ET(sqdist));
		       		else
			     		lp.set_a(j, i, 1);
		 	}
	   	}
	   	lp.set_b(i, roid[i].second);
     	}
	Solution sol = CGAL::solve_linear_program(lp,ET());
	if(sol.is_infeasible() || sol.objective_value() > e)	
		std::cout << "n\n";
	else
		std::cout << "y\n";

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	int t; std::cin >> t;
	while(t--)
		solve();
}
