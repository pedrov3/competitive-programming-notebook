struct median {
  multiset<int> l, r;
  int lsum = 0, rsum = 0;
  void balance() {
    int sz = l.size() + r.size();
    int target = (sz + 1) / 2;
    while (l.size() < target) {
      auto it = r.begin();
      l.emplace(*it);
      lsum += *it;
      rsum -= *it;
      r.erase(it);
    }
    while (l.size() > target) {
      auto it = --l.end();
      lsum -= *it;
      rsum += *it;
      r.emplace(*it);
      l.erase(it);
    }
  }
  void add(int x) {
    if (l.empty() || x < *l.rbegin()) {
      l.emplace(x);
      lsum += x;
    } else {
      rsum += x;
      r.emplace(x);
    }
    balance();
  }
  int get() { return *l.rbegin(); }
  int solve() {
    int med = *l.rbegin();
    return med * l.size() - lsum + rsum - med * r.size();
  }
};
