int basis[D], sz;

void insertVector(int mask) {
  for (int i = 0; i < D; i++) {
    if ((mask & 1LL << i) == 0) continue;
    if (!basis[i]) {
      basis[i] = mask;
      ++sz;
      return;
    }
    mask ^= basis[i];
  }
}
