vi s, c, lcp;

void count_sort(vector<int> &s, vector<int> &c) {
  int n = s.size();

  vector<int> cnt(n, 0);
  for (auto &x : c) cnt[x]++;

  vector<int> pos(n);

  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }

  vector<int> s_new(n);
  for (auto &x : s) {
    s_new[pos[c[x]]] = x;
    ++pos[c[x]];
  }
  s = s_new;
}

void build_suf(string &str) {
  str += "$";
  int n = str.size();
  c.resize(n);
  s.resize(n);

  // Construir r^0
  {
    vector<pair<char, int>> tmp(n);
    for (int i = 0; i < n; i++) {
      tmp[i].first = str[i];
      tmp[i].second = i;
    }

    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) s[i] = tmp[i].second;

    c[s[0]] = 0;
    for (int i = 1; i < n; i++)
      c[s[i]] = c[s[i - 1]] + int(tmp[i].first != tmp[i - 1].first);
  }

  int k = 0;
  while ((1 << k) < n) {
    // Ja esta ordenada pela segunda metade
    for (auto &x : s) x = ((x - (1 << k)) % n + n) % n;

    // Ordenar a primeira metade
    count_sort(s, c);

    // Novas classes de equivalência
    vector<int> c_new(n);
    c_new[s[0]] = 0;
    for (int i = 1; i < n; i++) {
      ii prev = {c[s[i - 1]], c[(s[i - 1] + (1 << k)) % n]};
      ii cur = {c[s[i]], c[(s[i] + (1 << k)) % n]};

      c_new[s[i]] = c_new[s[i - 1]];
      if (cur != prev) c_new[s[i]]++;
    }
    c = c_new;
    ++k;
  }
}

void build_lcp(string &str) {
  int n = str.size();
  lcp.resize(n);
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pi = c[i];
    int prev = s[pi - 1];
    while (str[i + k] == str[prev + k]) k++;
    lcp[pi] = k;
    k = max(k - 1, 0);
  }
}

void echo_suf(string str) {
  int n = str.size();
  for (int i = 0; i < n; i++) {
    cout << "s[" << i << "]: " << s[i] << ", lcp: " << lcp[i] << ", ";
    cout << str.substr(s[i], n - s[i]) << "\n";
  }
}

int main() {
  string str;
  cin >> str;

  build_suf(str);
  build_lcp(str);
  echo_suf(str);
}
