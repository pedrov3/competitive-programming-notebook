template <typename T>
struct segtree {
  int n;
  vector<T> seg;
  segtree(int _n) : n(_n), seg(2 * _n) {}
  T get(int l, int r) {
    T left = T(), right = T();
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) left = left + seg[l++];
      if (r & 1) right = seg[--r] + right;
    }
    return left + right;
  }
  void set(int i, T v) {
    seg[i += n] = v;
    while (i >>= 1) seg[i] = seg[i * 2] + seg[i * 2 + 1];
  }
};
struct item {
  item operator+(item oth) {}
};
