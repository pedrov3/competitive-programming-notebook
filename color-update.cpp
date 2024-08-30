struct ColorUpdate {
  struct Node {
    int l, r;
    mutable int v;

    Node(const int &_l, const int &_r, const int &_v) : l(_l), r(_r), v(_v) {}

    bool operator<(const Node &o) const { return l < o.l; }
  };

  int n;
  set<Node> s;

  ColorUpdate(int _n) : n(_n) {
    s.emplace(1, n, 1);  // TODO:
  }

  auto split(int x) {
    if (x > n) return s.end();
    auto it = --s.upper_bound(Node{x, 0, 0});
    if (it->l == x) return it;
    int l = it->l, r = it->r, v = it->v;
    s.erase(it);
    s.emplace(l, x - 1, v);
    return s.emplace(x, r, v).first;
  }

  void assign(int l, int r, int v) {
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    s.emplace(l, r, v);
  }

  int getv(int x) {
    auto it = --s.upper_bound(Node{x, 0, 0});
    return it->v;
  }

  void apply(int l, int r) {  // TODO:
    auto itr = split(r + 1), itl = split(l);
    for (; itl != itr; ++itl) {
      auto [a, b, c] = *itl;
    }
  }
};
