ll expbin(ll a, ll b) {
  if (b == 0LL) return 1LL;
  if (b & (1LL)) return a * expbin(a, b - 1);
  ll tmp = expbin(a, b / 2);
  return tmp * tmp;
}
