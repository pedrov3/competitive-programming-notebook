#define to_i(ch) (ch - 'a' + 1)
const ll P = 1e9 + 7;
const int MAX_PREC = 10;

mt19937 rmg((int)chrono::steady_clock::now().time_since_epoch().count());

bool flag = false;
vi b;
vector<vi> p;

struct hash_str {
  vector<vi> h;
  hash_str(string &s) {
    int n = s.size();
    h.resize(MAX_PREC);

    if (!flag) {
      p.resize(MAX_PREC);
      b.resize(MAX_PREC);
      for (int k = 0; k < MAX_PREC; k++) {
        b[k] = uniform_int_distribution<ll>(256, int(1e9 + 7) - 1)(rmg);
        p[k].resize(n);
        p[k][0] = 1;
        for (int i = 1; i < n; i++) {
          p[k][i] = (p[k][i - 1] * b[k]) % P;
        }
      }

      flag = true;
    }
    // h[0] = s[0]
    // h[1] = s[0] * b + s[1]
    // h[2] = s[0] * b^2 + s[1] * b + s[2]
    // h[3] = s[0] * b^3 + s[1] * b^2 + s[2] * b + s[3]
    for (int k = 0; k < MAX_PREC; k++) {
      h[k].resize(n);
      h[k][0] = to_i(s[0]);
      for (int i = 1; i < n; i++) {
        h[k][i] = (h[k][i - 1] * b[k] + to_i(s[i])) % P;
      }
    }
  }
  vi substr(int l, int r) {
    vi retval;
    if (l == 0) {
      for (int k = 0; k < MAX_PREC; k++) {
        retval.emplace_back(h[k][r]);
      }
      return retval;
    }
    for (int k = 0; k < MAX_PREC; k++) {
      ll ans = (h[k][r] - h[k][l - 1] * p[k][r - l + 1]) % P;
      if (ans < 0) {
        ans += P;
      }
      retval.emplace_back(ans);
    }
    return retval;
  }

  vi f(int i, char ch) {
    int a = i - 1;
    int _b = p[0].size() - i - 1;
    vi ha = a >= 0 ? sub_hash(0, a) : vi(MAX_PREC, 0LL);
    vi hb = i < (int)p[0].size() - 1 ? sub_hash(i + 1, p[0].size() - 1)
                                     : vi(MAX_PREC, 0LL);

    vi retval(MAX_PREC);
    for (int k = 0; k < MAX_PREC; k++) {
      retval[k] = (((ha[k] * (_b >= p[k].size() - 1 ? 1 : p[k][_b + 1])) % P +
                    (to_i(ch) * p[k][_b]) % P) %
                       P +
                   hb[k]) %
                  P;
    }
    return retval;
  }
};

int who[MAX][26];

bool __cmp(vi &a, vi &b) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  string s, p;
  cin >> s >> p;

  int n = s.size();
  int m = p.size();

  hash_str hs(s), hp(p);

  map<vi, ii> tab;
  vi hash_orig = hp.sub_hash(0, m - 1);

  // Pegar todos os hashes do padrão, para cada uma das alterações
  for (int i = 0; i < m; i++) {
    for (char ch = 'a'; ch <= 'z'; ch++) {
      vi val = hp.f(i, ch);
      //	cout << val[0] << "\n";
      tab[val] = make_pair(i, p[i]);
    }
  }

  int total = 0;
  for (int i = 0; i < n - m + 1; i++) {
    vi val = hs.sub_hash(i, i + m - 1);
    int pos;
    char ch;
    if (tab.find(val) == tab.end()) {
      continue;
    }
    total += int(__cmp(val, hash_orig));

    tie(pos, ch) = tab[val];
    who[i + pos][ch - 'a']++;
  }

  int q;
  cin >> q;
  while (q--) {
    int i;
    char ch;
    cin >> i >> ch;
    --i;

    int ans = total + who[i][ch - 'a'] - who[i][s[i] - 'a'];
    cout << ans << "\n";
  }
  return 0;
}
