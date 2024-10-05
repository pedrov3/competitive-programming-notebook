const int MAX = 1000006;

struct node {
  int len, link;
  map<int, int> nxt;
};

node st[MAX * 2];
int sz, last;

void sa_init() { // TODO: chamar antes de usar
  st[0].len = sz = last = 0;
  st[0].link = -1;
  sz++;
}

void sa_extend(int c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].nxt.count(c)) {
    st[p].nxt[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].nxt[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone].len = st[p].len + 1;
      st[clone] = st[q].nxt;
      st[clone].link = st[q].link;
      while (p != -1 && st[p].nxt[c] == q) {
        st[p].nxt[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
