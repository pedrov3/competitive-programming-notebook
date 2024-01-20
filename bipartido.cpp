#define MAX 3 * (212345)  // TODO

// TODO: meu codigo do dsu

int offset = 212345;
int bipartido = 1;

void special_join(int u, int v) {
  join(u, v + offset);
  join(u + offset, v);
  if (__find(u) == __find(u + offset) || __find(v) == __find(v + offset)) {
    bipartido = 0;
  }
}
