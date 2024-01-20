int ninv(vector<int> &vet) {
  ordered_set<int> s;
  ll ans = 0;
  for (int i = 0; i < vet.size(); ++i) {
    ans += (s.size() - s.order_of_key(vet[i]));
    s.insert(vet[i]);
  }
  return ans;
}
