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

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vector<ii> vet(n);
    set<ii> s;
    for (auto &[a, b] : vet){
        cin >> a >> b;
        s.emplace(a, b);
        for (int i=-10; i <= 10; i++){
            int mx = -oo;
            for (auto &[aa, bb] : s){
                chmax(mx, aa * i + bb);
            }
            cout << mx << " ";
        }
        cout << "\n";
    }
}
