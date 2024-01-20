int b[MAX];
void kmpp(string &p) {
  int i = 0, j = -1;
  b[0] = -1;
  int n = p.size();
  while (i < n) {
    while (j >= 0 && p[i] != p[j]) j = b[j];
    ++i, ++j;
    b[i] = j;
  }
}

bool kmp(string &t, string &p) {
  int i = 0, j = 0, n = t.size(), m = p.size();
  while (i < n) {
    while (j >= 0 && t[i] != p[j]) j = b[j];
    ++i, ++j;
    if (j == m) {
      j = b[j];
      return true;
    }
  }
  return false;
}
