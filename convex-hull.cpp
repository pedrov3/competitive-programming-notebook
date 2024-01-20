#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
const ll oo = 1987654321987654321;

template <class It>
void db(It b, It e) {
  for (auto it = b; it != e; it++) cout << *it << ' ';
  cout << endl;
}

#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
using pt = complex<double>;

#define px real()
#define py imag()

struct cmp {
  bool operator()(const pt &a, const pt &b) const {
    return a.px < b.px || (a.px == b.px && a.py < b.py);
  }
};

double dot(pt a, pt b) { return (conj(a) * b).px; }
double cross(pt a, pt b) { return (conj(a) * b).py; }
pt vec(pt a, pt b) { return b - a; }
int sgn(double v) { return (v > -EPS) - (v < EPS); }
// -1 (cw), 0 (colinear), +1 (ccw)
int seg_ornt(pt a, pt b, pt c) { return sgn(cross(vec(a, b), vec(a, c))); }
int ccw(pt a, pt b, pt c, bool col) {
  int o = seg_ornt(a, b, c);
  return (o == 1) || (o == 0 && col);
}
const double PI = acos(-1);
double angle(pt a, pt b, pt c) {
  return abs(remainder(arg(a - b) - arg(c - b), 2.0 * PI));
}

double dist(pt a, pt b) {
  double dx = a.px - b.px;
  double dy = a.py - b.py;
  return sqrt(dx * dx + dy * dy);
}

// O(n lg n)
vector<pt> convex_hull(vector<pt> &ps, bool col = false) {
  int k = 0, n = ps.size();
  vector<pt> ans(2 * n);
  sort(ps.begin(), ps.end(), [](pt a, pt b) {
    return make_pair(a.px, a.py) < make_pair(b.px, b.py);
  });
  for (int i = 0; i < n; i++) {
    while (k >= 2 && !ccw(/* lower hull */
                          ans[k - 2], ans[k - 1], ps[i], col)) {
      k--;
    }
    ans[k++] = ps[i];
  }
  if (k == n) {
    ans.resize(n);
    return ans;
  }
  for (int i = n - 2, t = k + 1; i >= 0; i--) {
    while (k >= t && !ccw(/* upper hull */
                          ans[k - 2], ans[k - 1], ps[i], col)) {
      k--;
    }
    ans[k++] = ps[i];
  }
  ans.resize(k - 1);
  return ans;
}

vector<pt> convex_hull(vector<ii> &pontos) {
  set<pt, cmp> s_ps;
  for (auto &[x, y] : pontos) {
    s_ps.insert(pt(x, y));
  }
  vector<pt> ps;
  for (auto &x : s_ps) {
    ps.push_back(x);
  }
  vector<pt> hull = convex_hull(ps, true);
  return hull;
}
