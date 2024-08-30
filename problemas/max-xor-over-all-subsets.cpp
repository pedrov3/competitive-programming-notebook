// Given a set S of size 1 <= n <= 10^5 with elements 0 <= ai < 2^20. What is
// the maximum possible xor of the elements of some subset of S?
const int LOG_A = 64;
int basis[LOG_A];

void insertVector(int mask) {
  for (int i = LOG_A - 1; i >= 0; i--) {
    if ((mask & 1 << i) == 0) continue;

    if (!basis[i]) {
      basis[i] = mask;
      return;
    }
    mask ^= basis[i];
  }
}

int maxXor() {
  int ans = 0;

  for (int i = LOG_A - 1; i >= 0; i--) {
    if (!basis[i]) continue;

    if (ans & 1 << i) continue;

    ans ^= basis[i];
  }
  return ans;
}
