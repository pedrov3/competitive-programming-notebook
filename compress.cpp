vector<ii> tmp;

void compress(vi &vet) {
  int n = vet.size();
  tmp.resize(n);
  for (int i = 0; i < n; i++) {
    tmp[i].first = vet[i];
    tmp[i].second = i;
  }
  sort(tmp.begin(), tmp.end());
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && tmp[i].first != tmp[i - 1].first) cnt++;
    vet[tmp[i].second] = cnt;
  }
}
