#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // opcional
#include <ext/pb_ds/detail/standard_policies.hpp> // opcional
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds; // opcional
using namespace std;

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // opcional

template <class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // opcional

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef vector<int> vi;
const ll oo = 1987654321987654321;

template <class It>
void db(It b, It e) { // opcional
  for (auto it = b; it != e; it++) cout << *it << ' ';
  cout << endl;
}

signed main() { 
    cin.tie(0)->sync_with_stdio(0); 

}
