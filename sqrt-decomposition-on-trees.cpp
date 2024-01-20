int B = ceil(sqrt(h_mx)) + gen(1, 100);
for (int i = 0; i < h_mx; i += B) {
  int mi = -1;
  for (int j = 0; j < B; j++) {
    int id = i + j;
    if (!by_height[id].empty()) {
      if (mi == -1 || (by_height[mi].size() > by_height[id].size())) {
        mi = id;
      }
    }
  }
  if (mi != -1) {
    for (auto &u : by_height[mi]) {
      for (auto &v : by_height[mi]) {
        if (u <= v) {
          tab[ii(u, v)] = solve(u, v);
        }
      }
    }
    for (auto &u : by_height[mi]) {
      special[u] = true;
    }
  }
}
