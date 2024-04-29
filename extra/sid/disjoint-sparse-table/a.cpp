#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define all(x) x.begin(), x.end()

using namespace __gnu_pbds;
using namespace std;

template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;

template<class T> using ordered_multiset = tree<T, null_type , less_equal<T> , rb_tree_tag , tree_order_statistics_node_update>;

typedef long long ll; 
typedef pair<int, int> ii; 
typedef tuple<int, int, int> iii;
typedef vector<int> vi; 
const ll oo = 1987654321987654321;

template<class It> void db(It b, It e) {
    for (auto it = b; it != e; it++) cout << *it << ' ';
    cout<< endl;
}

int op(int a, int b){
    return min(a, b);
}

#define MAXN 112345
#define LOGN 18
int tab[LOGN][MAXN];

void build(vi &vet){
    int N = vet.size();
    int n = 1;
    while (n < N) n *= 2;
    for (int i=0; (1<<i) < n; i++){
        int sz = 1<<i;
        for (int m=0; m < n;  m += 2 * sz){
            tab[i][m + sz - 1] = vet[m + sz - 1];
            for (int j=1; j < sz; j++){
                tab[i][m + sz - 1 - j] = op(tab[i][m + sz -1 - j + 1], vet[m + sz - j - 1]);
            }
        }
        for (int m=sz; m < n;  m += 2 * sz){
            tab[i][m] = vet[m];
            for (int j=1; j < sz; j++){
                tab[i][m + j] = op(tab[i][m + j-1], vet[m + j]);
            }
        }
    }
}

int get(int l, int r){
    if (l == r) return tab[0][l];
    int h = __builtin_clz(1) - __builtin_clz(l ^ r);
    return op(tab[h][l], tab[h][r]);
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    vi vet(n);
    for (auto &x: vet) cin >> x;
    build(vet);

}

