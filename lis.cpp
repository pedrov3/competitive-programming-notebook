vector<ll> bit(MAX, 0LL);

void add(int i, ll delta) {
  for (; i < MAX; i += i & (-i)) bit[i] = max(bit[i], delta);
}

ll get(int i) {
  if (i <= 0) return 0LL;
  ll ans = 0LL;
  for (; i > 0; i -= i & (-i)) ans = max(ans, bit[i]);
  return ans;
}

int lis(vi &vet) {
  int n = vet.size();
  vector<ii> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i].first = vet[i];
    tmp[i].second = -(i + 1);
  }
  sort(all(tmp));
  int ans = 0;
  fill(all(bit), 0);
  for (int i = 0; i < n; i++) {
    int pos = -tmp[i].second;
    int now = get(pos - 1);
    ans = max(ans, now + 1);
    add(pos, now + 1);
  }
  return ans;
}
