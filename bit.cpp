vector<int> bit(MAX, 0);

void addbit(int i, int delta) {
  for (; i < MAX; i += i & (-i)) bit[i] += delta;
}

int getbit(int i) {
  int ans = 0;
  for (; i > 0; i -= i & (-i)) ans += bit[i];
  return ans;
}

int getbit(int l, int r) { return getbit(r) - getbit(l - 1); }
