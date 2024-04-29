#include <bits/stdc++.h>
#define MAXN 100
#define MAXM 100
#define MAXQ 100
#define MAXV 100000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const ll oo = 1987654321987654321;

mt19937 rnd;
ll gen(ll a, ll b) {
  uniform_int_distribution<ll> dist(a, b);
  return dist(rnd);
}

int main(int argc, char *argv[]) {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  if (argc < 2) {
    cout << "usage: " << argv[0] << " <seed>\n";
    exit(1);
  }
  rnd = mt19937(atoi(argv[1]));

 
  int n = MAXN;
  int m = MAXM;
  cout << n << " " << m << "\n";
  for (int i=0; i < n; i++){
    for (int j=0; j < m; j++){
        cout << gen(1, MAXV) << " ";
    }
    cout << "\n";
  }

  int q;
  q = MAXQ;
  cout << q << "\n";
  while (q--){
    int op = gen(1, 2);
    cout << op << " ";
    if (op == 1){ // get
        int lx, rx, ly, ry;
        lx = gen(1, MAXN);
        rx = gen(1, MAXM);
        ly = gen(lx, MAXN);
        ry = gen(rx, MAXM);
        cout << lx << " " << rx << " " << ly << " " << ry << "\n";
    }else{// add
        int lin, col, delta;
        lin = gen(1, MAXN);
        col = gen(1, MAXM);
        delta = gen(0, MAXV);
        cout << lin << " " << col << " " << delta << "\n";
    }
  }
}
