#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

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

const int maxn = 30;

#define K 2
struct node {
  int nxt[K], term = 0, occ = 0;
  node() { memset(nxt, -1, sizeof(nxt)); }
};
vector<node> trie;

void add(int x) {
  int u = 0;
  for (int i = 0; i < maxn; i++) {
    int c = ((1LL << (maxn - i - 1)) & x) > 0;
    if (trie[u].nxt[c] == -1) {
      trie[u].nxt[c] = trie.size();
      trie.emplace_back();
    }
    u = trie[u].nxt[c];
    trie[u].occ++;
  }
  trie[u].term = 1;
}

void rem(int x) {
  int u = 0;
  for (int i = 0; i < maxn; i++) {
    int c = ((1LL << (maxn - i - 1)) & x) > 0;
    int prev = u;
    u = trie[u].nxt[c];
    trie[u].occ--;
    if (trie[u].occ == 0) {
      trie[prev].nxt[c] = -1;
    }
  }
}

int solve(int x, int u = 0, int h = (maxn - 1)) {
  if (h == -1) return 0;
  int bit = (x & (1 << h)) > 0;
  if (trie[u].nxt[bit ^ 1] != -1) {
    return solve(x, trie[u].nxt[bit ^ 1], h - 1) | (1 << h);
  } else if (trie[u].nxt[bit] != -1) {
    return solve(x, trie[u].nxt[bit], h - 1);
  } else {
    return 0;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  trie.emplace_back();

  int t;
  cin >> t;
  add(0);
  while (t--) {
    char op;
    int x;
    cin >> op >> x;
    if (op == '+') {
      add(x);
    } else if (op == '-') {
      rem(x);
    } else {
      cout << solve(x) << "\n";
    }
  }


