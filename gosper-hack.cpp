void GospersHack(int n, int k, function<void(ll)> f) {
  int msk = (1 << k) - 1;
  int limit = (1 << n);
  while (msk < limit) {
    f(msk);
    int c = msk & -msk;
    int r = msk + c;
    set = (((r ^ set) >> 2) / c) | r;
  }
}
