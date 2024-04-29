#include <bits/stdc++.h>
#define MAX 112
#define int long long
using namespace std;

typedef long double ld; 
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<int> vi; 
const ll oo = 1987654321987654321;

int mat[MAX][MAX];

int32_t main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++) for (int j=0; j < m; j++) cin >> mat[i][j];

    int q;
    cin >> q;
    while (q--){
        int op;
        cin >> op;
        if (op == 1){
            int lx, rx, ly, ry;
            cin >> lx >> rx >> ly >> ry;
            --lx, --rx;
            int sum = 0;
            for (int i=lx; i < ly; i++){
                for (int j=rx; j < ry; j++){
                    sum += mat[i][j];
                }
            }
            cout << sum << "\n";
        }else{
            int lin, col, x;
            cin >> lin >> col >> x;
            --lin, --col;
            mat[lin][col] += x; 
        }
    }

}


