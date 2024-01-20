#define to_i(ch) (ch - 'a')
#define K 26
struct node {
  int nxt[K], term = 0;
  node() { memset(nxt, -1, sizeof(nxt)); }
};
vector<node> trie;  // TODO: criar a raiz
void ins(string &w) {
  int n = w.size();
  int u = 0;
  for (int i = 0; i < n; i++) {
    int c = to_i(w[i]);
    if (trie[u].nxt[c] == -1) {
      trie[u].nxt[c] = trie.size();
      trie.emplace_back();
    }
    u = trie[u].nxt[c];
  }
  trie[u].term = 1;
}
