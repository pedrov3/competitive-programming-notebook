template<typename T>
struct segtree{
    int n;
    vector<T> seg;
    segtree(int _n) : n(_n), seg(4 * _n){}
    void set(int i, T v, int pos, int lx, int rx) {
      if (rx - lx == 1){
          seg[pos] = v;
          return;
      }
      int mid = lx + (rx - lx) / 2;
      if (i < mid) set(i, v, 2 * pos + 1, lx, mid);
      else set(i, v, 2 * pos + 2, mid, rx);
      seg[pos] = seg[2 * pos + 1] + seg[2 * pos + 2];
    }
    void set(int i, T v){ set(i, v, 0, 0, n); } 
    T get(int l, int r, int pos, int lx, int rx) {
      if (lx >= r || rx <= l) return T();
      if (lx >= l && rx <= r) return seg[pos];
      int mid = lx + (rx - lx) / 2;
      return get(l, r, 2 * pos + 1, lx, mid) + get(l, r, 2 * pos + 2, mid, rx);
    }
    T get(int l, int r){ return get(l, r, 0, 0, n); }
};
struct item {
  item operator+(item oth) {}
};
