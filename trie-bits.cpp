const int SZ = 60, K = 2;
struct TrieBits {
  struct node {
    int nxt[K], term = 0, occ = 0;
    node() { memset(nxt, -1, sizeof(nxt)); }
  };

  vector<node> trie;

  TrieBits() { trie.emplace_back(); }

  void add(int x) {
    int u = 0;
    for (int i = 0; i < SZ; i++) {
      int c = ((1LL << (SZ - i - 1)) & x) > 0;
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
    for (int i = 0, u = 0; i < SZ; i++) {
      int c = ((1LL << (SZ - i - 1)) & x) > 0;
      int prev = u;
      u = trie[u].nxt[c];
      trie[u].occ--;
      if (trie[u].occ == 0) {
        trie[prev].nxt[c] = -1;
      }
    }
  }

  int solve(int x, int u = 0, int h = (SZ - 1)) {
    if (h == -1) return 0;
    int bit = (x & (1LL << h)) > 0;
    if (trie[u].nxt[bit ^ 1] != -1) {
      return solve(x, trie[u].nxt[bit ^ 1], h - 1) | (1LL << h);
    } else if (trie[u].nxt[bit] != -1) {
      return solve(x, trie[u].nxt[bit], h - 1);
    } else {
      return 0;
    }
  }
};
