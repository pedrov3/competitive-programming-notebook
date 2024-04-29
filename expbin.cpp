ll expbin(ll a, ll b) {
  if (b == 0) return 1;
  if (b & 1) return a * expbin(a, b - 1);
  ll tmp = expbin(a, b / 2);
  return tmp * tmp;
}
