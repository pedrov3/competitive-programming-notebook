vi diff, pref1, pref2;

// tem algum caractere diferente?
bool has_diff(int l, int r) {  // [l, r)
  return (oth[r - 1] - oth[l]) > 0;
}

// todos os caracteres são iguais? 
bool is_equal(int l, int r) { // [l, r)
  return !has_diff(l, r);
}

// a string é alternada e.g. "ababab"
bool alternate(int l, int r) {  // [l, r)
  if ((r - l) <= 2) {
    return str[l] != str[l + 1];
  }
  --r;
  --r;
  if ((pref1[r] - pref1[l]) || (pref2[r] - pref2[l])) {
    return false;
  }
  return str[l] != str[l + 1];
}

void build(string str) {  // TODO
  int n = str.size();
  diff = vi(n + 1);
  for (int i = 0; i + 1 < n; i++) {
    diff[i + 1] = diff[i] + (str[i] != str[i + 1]);
  }

  vi even(n);
  for (int i = 0; i + 2 < n; i += 2) {
    even[i] = str[i] != str[i + 2];
  }

  vi odd(n);
  for (int i = 1; i + 2 < n; i += 2) {
    odd[i] = str[i] != str[i + 2];
  }

  pref1 = vi(n + 1);
  pref2 = vi(n + 1);
  partial_sum(all(even), pref1.begin() + 1);
  partial_sum(all(odd), pref2.begin() + 1);
}
