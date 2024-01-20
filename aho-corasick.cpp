#define to_i(ch) (ch - 'a');
#define MAX 112345
#define K 26

struct node {
  int nxt[K], term = 0, p, pc, link = -1, exi = -1, go[K], occ = 0;
  vi dx;
  node(int _p = 0, int _pc = 0) : p(_p), pc(_pc) {
    memset(nxt, -1, sizeof(nxt));
    memset(go, -1, sizeof(go));
  }
};

// TODO: criar o no raiz
vector<node> aca;  // aho-corasick automaton
int occ[MAX];
int go(int u, int c);

int link(int u) {
  if (aca[u].link != -1) return aca[u].link;
  return aca[u].link = ((aca[u].p == 0) ? 0 : go(link(aca[u].p), aca[u].pc));
}

int go(int u, int c) {
  if (aca[u].go[c] != -1) return aca[u].go[c];
  if (aca[u].nxt[c] != -1) return aca[u].go[c] = aca[u].nxt[c];

  return aca[u].nxt[c] = ((u == 0) ? 0 : go(link(u), c));
}
int exi(int u) {
  if (aca[u].exi != -1) return aca[u].exi;
  int v = link(u);
  return aca[u].exi = ((aca[u].p == 0 || aca[v].term) ? v : exi(v));
}
void process(string &word) {
  int n = word.size(), u = 0;
  for (int i = 0; i < n; i++) {
    int c = to_i(word[i]);
    u = go(u, c);
    for (int v = u; v != 0; v = exi(v)) {
      aca[v].occ++;
    }
  }
  for (auto &v : aca) {
    for (auto &i : v.dx) {
      occ[i] += v.occ;
    }
  }
}
void ins(string &word, int dx) {
  int n = word.size(), u = 0;
  for (int i = 0; i < n; i++) {
    int c = to_i(word[i]);
    if (aca[u].nxt[c] == -1) {
      aca[u].nxt[c] = aca.size();
      aca.emplace_back(u, c);
    }
    u = aca[u].nxt[c];
  }
  aca[u].term = 1;
  aca[u].dx.push_back(dx);
}
