// Problema: https://vjudge.net/problem/SPOJ-QTREE5
// TODO: simplificar

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag,
                              tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int> vi;
const ll oo = 1987654321987654321;

template <class It>
void db(It b, It e) {
  for (auto it = b; it != e; it++) cout << *it << ' ';
  cout << endl;
}
template <typename A>
istream& operator>>(istream& fin, vector<A>& v) {
  for (auto it = v.begin(); it != v.end(); ++it) fin >> *it;
  return fin;
}
template <typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p) {
  fin >> p.first >> p.second;
  return fin;
}

#define MAX 112345
#define LOGN 18

int p[MAX], h[MAX], n, tab[LOGN][MAX];
ll dist[MAX];

set<ii> closest[MAX];

int color[MAX];

vi adj[MAX];
int sz[MAX];
bool mark[MAX];

void dfs(int u, int _p) {
  p[u] = _p;
  for (auto& v : adj[u]) {
    if (v == _p) continue;
    dist[v] = dist[u] + 1;
    h[v] = h[u] + 1;
    dfs(v, u);
  }
}

void build() {
  dfs(0, 0);
  for (int j = 0; j < n; j++) tab[0][j] = p[j];
  for (int i = 1; i < LOGN; i++)
    for (int j = 0; j < n; j++) tab[i][j] = tab[i - 1][tab[i - 1][j]];
}

int goup(int u, int k) {
  for (int i = 0; i < LOGN; i++)
    if (k & (1LL << i)) u = tab[i][u];
  return u;
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  u = goup(u, h[u] - h[v]);
  if (u == v) return u;
  for (int i = LOGN - 1; i >= 0; i--)
    if (tab[i][u] != tab[i][v]) {
      u = tab[i][u];
      v = tab[i][v];
    }
  return tab[0][u];
}

ll solve(int u, int v) {  // Distancia entre dois vertices com custo
  if (u > v) swap(u, v);
  if (u == 0) return dist[v];
  return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

int dfs_sz(int u, int p = -1) {
  sz[u] = 1;
  for (auto& v : adj[u])
    if (v != p && !mark[v]) sz[u] += dfs_sz(v, u);
  return sz[u];
}

int dfs_cent(int u, int n, int p = -1) {
  for (auto& v : adj[u])
    if (v != p && !mark[v] && sz[v] >= (n >> 1)) return dfs_cent(v, n, u);
  return u;
}

int parc[MAX];

void centroid(int u = 0, int p = -1) {
  int c = dfs_cent(u, dfs_sz(u));
  mark[c] = 1;

  if (p == -1) p = c;
  parc[c] = p;

  for (auto& v : adj[c])
    if (!mark[v]) centroid(v, c);
}

void paint(int u) {
  // cout << "[paint] u: " << u + 1 << "\n";
  int _u = u;
  while (1) {
    int d = solve(u, _u);
    if (color[_u] == 0) {
      // cout << "adding (" << d << "," << _u + 1 << ") in " << u + 1 << ")\n";
      closest[u].emplace(d, _u);
    } else {
      // cout << "removing (" << d << "," << _u + 1 << ") from: " << u + 1 <<
      // "\n";
      assert(closest[u].count(ii(d, _u)));
      closest[u].erase(ii(d, _u));
    }
    if (parc[u] == u) break;
    u = parc[u];
  }
  color[_u] ^= 1;
}

int query(int u) {
  // cout << "[query] u: " << u + 1 << "\n";
  int _u = u;
  int retval = oo;
  while (1) {
    //   cout << "u: " << u << " " << solve(_u, u) + closest[u] << "\n";
    //  cout << "now: " << u + 1 << "\n";
    // cout << "closest: ";
    // for (auto &[d, v] : closest[u]){
    //  cout << "(" << d << "," << v + 1 << ") ";
    //}
    // db(all(closest[u]));
    // cout << "\n";
    retval = min(
        retval,
        solve(_u, u) + (closest[u].empty() ? oo : (closest[u].begin()->first)));
    if (parc[u] == u) break;
    u = parc[u];
  }
  return retval;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  build();
  centroid();

  int q;
  cin >> q;
  while (q--) {
    int op, u;
    cin >> op >> u;
    --u;
    if (op == 0) {  // paint
                    // cout << "[paint] u: " << u + 1 << "\n";
      paint(u);
    } else {  // query
      // cout << "[query] u : " << u + 1  << "\n";
      int retval = query(u);
      if (retval == oo) retval = -1;
      //  cout << "----> " ;
      cout << retval << "\n";
    }
  }
}
