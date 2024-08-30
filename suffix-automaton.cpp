struct node {
  int len, link;
  map<char, int> nxt;
};

node st[MAX * 2];
int sz, last;

void sa_init() {  // TODO: Chamar antes de usar
  st[0].len = 0;
  st[0].link = -1;
  sz = last = 0;
  sz++;
}

void sa_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && st[p].nxt.find(c) == st[p].nxt.end()) {
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
      st[clone].nxt = st[q].nxt;
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

bool substr(string &str) {
  int q = 0;
  int n = str.size();
  for (int i = 0; i < n; i++) {
    char c = str[i];
    if (st[q].nxt.find(c) == st[q].nxt.end()) {
      return false;
    }
    q = st[q].nxt[c];
  }
  return true;
}
