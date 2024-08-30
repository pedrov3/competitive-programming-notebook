#define to_i(ch) (ch - 'a');  // TODO
const int K = 26;             // TODO
struct node {
  int term = 0, p, pc, link = -1, exi = -1, occ = 0;
  vi nxt, go, ids;
  node(int _p = 0, int _pc = 0) : p(_p), pc(_pc), nxt(K, -1), go(K, -1) {}
};

vector<node> aca;  // TODO: criar o no raiz
int occ[MAX];
int go(int u, int c);

int link(int u) {
  if (aca[u].link != -1) return aca[u].link;
  return aca[u].link = !aca[u].p ? 0 : go(link(aca[u].p), aca[u].pc);
}

int go(int u, int c) {
  if (aca[u].go[c] != -1) return aca[u].go[c];
  if (aca[u].nxt[c] != -1) return aca[u].go[c] = aca[u].nxt[c];
  return aca[u].go[c] = !u ? 0 : go(link(u), c);
}

int exi(int u) {
  if (aca[u].exi != -1) return aca[u].exi;
  int v = link(u);
  return aca[u].exi = (!v || aca[v].term) ? v : exi(v);
}

void process(string word) {
  for (int i = 0, u = 0; i < word.size(); i++) {
    int c = to_i(word[i]);
    u = go(u, c);
    for (int v = u; v; v = exi(v)) {
      aca[v].occ++;
    }
  }
  for (auto &v : aca) {
    for (auto &i : v.ids) {
      occ[i] += v.occ;
    }
  }
}

void ins(string word, int id) {
  int u = 0;
  for (int i = 0; i < word.size(); i++) {
    int c = to_i(word[i]);
    if (aca[u].nxt[c] == -1) {
      aca[u].nxt[c] = aca.size();
      aca.emplace_back(u, c);
    }
    u = aca[u].nxt[c];
  }
  aca[u].term = 1;
  aca[u].ids.push_back(id);
}
