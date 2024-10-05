#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds; using namespace std;

template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update>; template<class T> using ordered_multiset = tree<T, null_type , less_equal<T> , rb_tree_tag , tree_order_statistics_node_update>; typedef long long ll;  typedef pair<int, int> ii;  typedef tuple<int, int, int> iii; typedef tuple<int, int, int, int> iiii; typedef vector<int> vi; 
const ll oo = 1987654321987654321;

template<class It> void db(It b, It e) { for (auto it = b; it != e; it++) cout << *it << ' '; cout<< endl; } template<typename A> istream& operator>>(istream& fin, vector<A>& v) { for (auto it = v.begin(); it != v.end(); ++it) fin >> *it; return fin; } template<typename A, typename B> istream& operator>>(istream& fin, pair<A, B>& p){ fin >> p.first >> p.second; return fin; } template<typename T> void chmin(T &a, T b){ a = min(a, b); } template<typename T> void chmax(T &a, T b){ a = max(a, b); } template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v) { os << "(" << v.first << "," << v.second << ")"; return os; }

int tamseg = 1e9 + 7;
struct item {
  int e = -1, d = -1, a = 0, b = -oo;
};


struct Lichao {
  vector<item> seg;
  item neutro;

  int _create() {
    seg.emplace_back();
    return seg.size() - 1;
  }

  Lichao() { _create(); }

  int get(int x, int pos, ll lx, ll rx) {
    if (pos == -1) return -oo;
    if (rx - lx == 1) return seg[pos].a * x + seg[pos].b;
    int mid = lx + (rx - lx) / 2;
    if (x < mid){
        return max(get(x, seg[pos].e, lx, mid), seg[pos].a * x + seg[pos].b);
    }else{
        return max(get(x, seg[pos].d, mid, rx), seg[pos].a * x + seg[pos].b);
    }
  }

  int get(int x) { return get(x, 0, -tamseg, tamseg); }

  void add(int a, int b, int pos, ll lx, ll rx) {
    int mid = lx + (rx - lx) / 2;
    if (seg[pos].a * mid + seg[pos].b < a * mid + b){
        swap(seg[pos].a, a);
        swap(seg[pos].b, b);
    }
    assert(seg[pos].a * mid + seg[pos].b >= a * mid + b);
    if (rx - lx == 1) {
      return;
    }
    if (seg[pos].a * lx + seg[pos].b < a * lx + b){
      if (seg[pos].e == -1) {
        int tmp = _create();
        seg[pos].e = tmp;
      }
      add(a, b, seg[pos].e, lx, mid);
    } else {
      if (seg[pos].d == -1) {
        int tmp = _create();
        seg[pos].d = tmp;
      }
      add(a, b, seg[pos].d, mid, rx);
    }
  }

  void add(int a, int b) { 
      add(a, b, 0, -tamseg, tamseg); 
  }
};


signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    Lichao lichao;
    for (int i=0; i < n; i++){
        int a, b;
        cin >> a >> b;
        lichao.add(a, b);
        for (int i=-10; i <= 10; i++){
            cout << lichao.get(i) << " ";
        }
        cout << "\n";
    }
}

