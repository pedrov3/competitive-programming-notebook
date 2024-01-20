int memo[20][2][4];

vi num2v(int n) {
  vi retval;
  if (n == 0) retval.push_back(0);
  while (n > 0) {
    retval.push_back(n % 10);
    n /= 10;
  }
  reverse(retval.begin(), retval.end());
  return retval;
}

int dp(vi &digitos, int i = 0, bool empatado = true, int x = 0) {
  if (i == digitos.size()) {
    return 1;
  }
  int &ans = memo[i][empatado][x];
  if (ans != -1) return ans;
  ans = 0;
  int r = empatado ? digitos[i] : 9;
  for (int val = 0; val <= r; val++) {
    bool new_empatado = empatado && val == r;
    ans += dp(digitos, i + 1, new_empatado, x);
  }
  return ans;
}
