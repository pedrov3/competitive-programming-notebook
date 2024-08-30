// TODO: B
auto f = [&](int l, int r, function<void(int i)> apply_elem,
             function<void(int i)> apply_block) {  // [l, r]  0-indexed
  int bl = l / B, br = r / B;
  if (bl == br) {
    for (int i = l; i <= r; i++) apply_elem(i);
    return;
  }
  for (int i = l; i <= (bl + 1) * B - 1; i++) apply_elem(i);
  for (int bi = bl + 1; bi <= br - 1; bi++) apply_block(bi);
  for (int i = br * B; i <= r; i++) apply_elem(i);
};
