ordered_set<ii> bit[MAX];

void insert(int x, int y) {
  for (int i = x; i < MAX; i += i & -i) bit[i].insert(ii(y, x));
}

void remove(int x, int y) {
  for (int i = x; i < MAX; i += i & -i) bit[i].erase(ii(y, x));
}

int get(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) ans += bit[i].order_of_key(ii(y + 1, 0));
  return ans;
}

int get(int lx, int ly, int rx, int ry) {
  return get(rx, ry) - get(rx, ly - 1) - get(lx - 1, ry) + get(lx - 1, ly - 1);
}
