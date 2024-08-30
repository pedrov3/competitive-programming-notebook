set<int>* small(int u, int p = 0) {
  set<int>* now = new set<int>(all(toadd[u]));
  for (auto& v : adj[u]) {
    if (v == p) continue;
    set<int>* oth = small(v, u);
    if (oth->size() > now->size()) swap(oth, now);
    (*now).insert(all((*oth)));
  }
  for (auto i : torem[u]) now->erase(i);
  ans[u] = now->size();
  return now;
}
