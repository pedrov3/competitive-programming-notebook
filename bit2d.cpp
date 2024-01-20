ll bit[MAX][MAX];

void add(int i, int j, ll v) {
  for (; i < MAX; i += i & (-i))
    for (int jj = j; jj < MAX; jj += jj & (-jj)) bit[i][jj] += v;
}

ll getbit(int i, int j) {
  ll sum = 0;
  for (; i; i -= i & (-i))
    for (int jj = j; jj; jj -= jj & (-jj)) sum += bit[i][jj];
  return sum;
}

ll getbit(int lx, int ly, int rx, int ry) {  // getbit(1, 1, lin, col)
  return getbit(rx, ry) - getbit(rx, ly - 1) - getbit(lx - 1, ry) +
         getbit(lx - 1, ly - 1);
}

void add(int lx, int ly, int rx, int ry, ll v) {  // canto superior esquerdo
  rx++;                                           // canto inferior direito
  ry++;
  add(lx, ly, +v);
  add(lx, ry, -v);
  add(rx, ly, -v);
  add(rx, ry, +v);
}
