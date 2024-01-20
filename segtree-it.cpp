
#define NEUTRAL 0
#define OP(X, Y) (X + Y)

const int N = MAX;
vector<int> t(2 * N);

int op_inclusive(int l, int r) {
  r++;
  int left = NEUTRAL, right = NEUTRAL;
  for (l += N, r += N; l < r; l /= 2, r /= 2) {
    if (l & 1) left = OP(left, t[l++]);
    if (r & 1) right = OP(right, t[--r]);
  }
  return OP(left, right);
}

void set_value(int i, int v) {
  t[i += N] = v;
  for (i /= 2; i > 0; i /= 2) t[i] = OP(t[i * 2], t[i * 2 + 1]);
}
