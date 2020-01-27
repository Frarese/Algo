#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <CGAL/QP_models.h>
#include <CGAL/QP_functions.h>
#include <CGAL/Gmpz.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K>  Triangulation;

// choose input type (input coefficients must fit)
typedef long IT;
// choose exact type for solver (CGAL::Gmpz or CGAL::Gmpq)
typedef CGAL::Gmpz ET;

// program and solution types
typedef CGAL::Quadratic_program<ET> Program;
typedef CGAL::Quadratic_program_solution<ET> Solution;

#define to_index(q, z) (m*q + z)

using std::cout;
using std::cin;
using std::vector;

struct Warehouse {
    int supply, alc;
    std::set<int> cont;
};

struct Station {
    int demand, uba;
    std::set<int> cont;
};

struct Contour {
    long x, y;
    K::FT r2;
};


double floor_to_double(const CGAL::Quotient<ET>& x)
{
    double a = std::floor(CGAL::to_double(x));
    while (a > x) a -= 1;
    while (a+1 <= x) a += 1;
    return a;
}

vector<vector<int>> create_table(const vector<K::Point_2>& s_pos,
                                 const vector<K::Point_2>& w_pos,
                                 const vector<Contour>& contours) {
    int n = w_pos.size();
    int m = s_pos.size();
    vector<vector<int>> ret(n, vector<int>(m, 0));
    Triangulation t;
    t.insert(w_pos.begin(),w_pos.end());
    t.insert(s_pos.begin(),s_pos.end());

    for (int i = 0; i < contours.size(); ++i) {
        K::Point_2 center(contours[i].x, contours[i].y);

        auto nv = t.nearest_vertex(center);
        if (CGAL::squared_distance(nv->point(), center) >= contours[i].r2) continue;

        for (int j = 0; j < n; ++j) {
            bool w_in = CGAL::squared_distance(w_pos[j], center) <= contours[i].r2;
            for (int k = 0; k < m; ++k) {
                bool s_in = CGAL::squared_distance(s_pos[k], center) <= contours[i].r2;
                if (w_in != s_in) {
                    ret[j][k]++;
                }
            }
        }
    }
    return ret;
}

void testcase() {
    int n, m, c;
    cin >> n >> m >> c;

    vector<Warehouse> w(n);
    vector<K::Point_2> w_pos(n);
    for (int i = 0; i < n; ++i) {
        long x, y;
        cin >> x >> y >> w[i].supply >> w[i].alc;
        w_pos[i] = K::Point_2(x, y);
    }

    vector<Station> s(m);
    vector<K::Point_2> s_pos(m);
    for (int i = 0; i < m; ++i) {
        long x, y;
        cin >> x >> y >> s[i].demand >> s[i].uba;
        s_pos[i] = K::Point_2(x, y);
    }

    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> r[i][j];
        }
    }

    vector<Contour> l(c);
    for (int i = 0; i < c; ++i) {
        long r;
        cin >> l[i].x >> l[i].y >> r;
        l[i].r2 = K::FT(r*r);
    }


    auto table = create_table(s_pos, w_pos, l);
    // begin linear program
    Program lp (CGAL::SMALLER, true, 0, false, 0);

    int eq_cnt = 0;
    // cap supply
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            lp.set_a(to_index(i, j), eq_cnt,  1);
        }
        lp.set_b(eq_cnt, w[i].supply);
        ++eq_cnt;
    }

    // guarantee supply
    // and cap alc
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            lp.set_a(to_index(j, i), eq_cnt, 1);
            lp.set_a(to_index(j, i), eq_cnt+1, -1);

            lp.set_a(to_index(j, i), eq_cnt+2, w[j].alc);
        }
        lp.set_b(eq_cnt, s[i].demand);
        lp.set_b(eq_cnt+1, -s[i].demand);
        lp.set_b(eq_cnt+2, 100*s[i].uba);

        eq_cnt += 3;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long t = table[i][j];
            lp.set_c(to_index(i,j), -100*r[i][j] + t);
        }
    }

    Solution sol = CGAL::solve_linear_program(lp, ET());

    if (sol.is_infeasible()) {
        cout << "RIOT!\n";
    } else {
        cout << (long)floor_to_double(-sol.objective_value()/100) << "\n";
    }
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        testcase();
    }
}
