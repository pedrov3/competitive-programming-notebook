// Devolve a quantidade de coordenadas inteiras entre dois pontos
// TODO: isso está muito grande para um problema simples
ll qtde_div(ll x, ll l, ll r) {
  if ((l < 0 && r < 0) || (l > 0 && r > 0)) {
    l = llabs(l);
    r = llabs(r);
    if (l > r) swap(l, r);
    return r / x - (l - 1) / x;
  } else {
    l = llabs(l);
    r = llabs(r);
    if (l > r) swap(l, r);
    if (l == 0) return r / x + 1;

    return r / x + l / x + 1;
  }
}

ll extremos_inteiros(ll ax, ll ay, ll bx, ll by) {
  ll num = llabs(by - ay);
  ll den = llabs(bx - ax);

  if (den == 0) {
    return max(by, ay) - min(by, ay) + 1;
  } else if (num == 0) {
    return max(bx, ax) - min(bx, ax) + 1;
  }
  ll x = 1;
  if (num % den == 0) {
    x = 1;
  } else {
    x = den / __gcd(den, num);
  }
  ll ans = qtde_div(x, min(ax, bx) - max(ax, bx), 0);
  return ans;
}
