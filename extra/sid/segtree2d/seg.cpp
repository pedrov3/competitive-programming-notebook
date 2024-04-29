#include <bits/stdc++.h>
#define int long long

using namespace std;

typedef long double ld; 
typedef long long ll; 
typedef pair<int, int> ii; 
typedef vector<int> vi; 
const ll oo = 1987654321987654321;

struct item {
  int e = -1, d = -1, raiz = -1;
  int val = 0; 
};

void _merge(item &a, item &b, item &c) { a.val = b.val + c.val; }

vector<item> seg;
item neutro;
int tamseg = 1<<19;

int _create() {
  seg.emplace_back();
  return seg.size() - 1;
}

void initseg() { 
    _create();
}

ll getseg(ll l, ll r, int pos, ll lx, ll rx) { // 1d
  if (lx >= r || rx <= l) return 0LL;
  if (pos == -1) return 0LL;
  if (lx >= l && rx <= r) {
    return seg[pos].val;
  }
  ll mid = lx + (rx - lx) / 2;
  ll x = getseg(l, r, seg[pos].e, lx, mid);
  ll y = getseg(l, r, seg[pos].d, mid, rx);
  return x + y;
}

void addseg(ll i, int v, int pos, ll lx, ll rx) {
    assert(pos != -1);
  if (rx - lx == 1) {
    seg[pos].val += v;
    return;
  }
  ll mid = lx + (rx - lx) / 2;
  if (i < mid) {
    if (seg[pos].e == -1) {
      int tmp = _create();
      seg[pos].e = tmp;
    }
    addseg(i, v, seg[pos].e, lx, mid);
  } else {
    if (seg[pos].d == -1) {
      int tmp = _create();
      seg[pos].d = tmp;
    }
    addseg(i, v, seg[pos].d, mid, rx);
  }
  int e = seg[pos].e;
  int d = seg[pos].d;
  _merge(seg[pos], e == -1 ? neutro : seg[e], d == -1 ? neutro : seg[d]);
}

ll getseg(ll y1, ll x1, ll y2, ll x2, int pos, ll lx, ll rx) { // 2d TODO: isso ficou confuso
  if (lx >= x2 || rx <= x1) return 0LL;
  if (pos == -1) return 0LL;
  if (lx >= x1 && rx <= x2) {
    return getseg(y1, y2, seg[pos].raiz, 0, tamseg); 
  }
  ll mid = lx + (rx - lx) / 2;
  ll x = getseg(y1, x1, y2, x2, seg[pos].e, lx, mid);
  ll y = getseg(y1, x1, y2, x2, seg[pos].d, mid, rx);
  return x + y;
}

void addseg(ll lin, ll col, int v, int pos, ll lx, ll rx) {
  if (rx - lx == 1) {
    //cout << "(fim)[" << lx << "," <<rx << ") col: " << col << " lin: " << lin << " raiz: " << pos << "\n";
    if (seg[pos].raiz == -1){
      int tmp = _create();
      seg[pos].raiz = tmp;
    //  cout << " sem raiz\n";
    }
     addseg(lin, v, seg[pos].raiz, 0, tamseg);
 //   cout << "  " << getseg(lin, lin + 1, seg[pos].raiz, 0, tamseg) << " <---\n";;
    return;
  }
  ll mid = lx + (rx - lx) / 2;
  if (col < mid) {
   // cout << "(left)[" << lx << "," <<rx << ") col: " << col << " lin: " << lin <<  " raiz: " << pos << "\n";
    if (seg[pos].e == -1) {
      int tmp = _create();
      seg[pos].e = tmp;
    }
    addseg(lin, col, v, seg[pos].e, lx, mid);
  } else {
    //cout << "(right)[" << lx << "," <<rx << ") col: " << col << " lin: " << lin << " raiz: " << pos << "\n";
    if (seg[pos].d == -1) {
      int tmp = _create();
      seg[pos].d = tmp;
    }
    addseg(lin, col, v, seg[pos].d, mid, rx);
  }
  
  if (seg[pos].raiz == -1){
      int tmp = _create();
      seg[pos].raiz = tmp;
  }
  addseg(lin, v, seg[pos].raiz, 0, tamseg);
  //int e = seg[pos].e;
  //int d = seg[pos].d;
  // TODO: nao tem merge?
  // _merge(seg[pos], e == -1 ? neutro : seg[e], d == -1 ? neutro : seg[d]);
}


int32_t main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    initseg();
    int n, m;
    cin >> n >> m;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            int x;
            cin >> x;
            addseg(i,j, x, 0, 0, tamseg);
        }
    }
    /*
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            cout << getseg(i, j, i + 1, j + 1, 0, 0, tamseg) << " ";
        }
        cout << "\n";
    }
    */

    int q;
    cin >> q;
    while (q--){
        int op;
        cin >> op;
        if (op == 2){
            int lin, col, x;
            cin >> lin >> col >> x;
            --lin, --col;
             addseg(lin, col, x, 0, 0, tamseg);
        }else{
            int lx, rx, ly, ry;
            cin >> lx >> rx >> ly >> ry;
            --lx, --rx;
            assert(lx < ly);
            assert(lx < ly);
            cout << getseg(lx, rx, ly, ry, 0, 0,tamseg) << "\n";
        }   
    }
}
