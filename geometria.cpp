const ld EPS = 1e-12;

struct point {
  ld x, y;
  point(ld _x, ld _y) : x(_x), y(_y) {}
  point() {}
};

struct vet {
  ld x, y;
  vet(ld _x, ld _y) : x(_x), y(_y) {}
  vet(point a, point b) : x(b.x - a.x), y(b.y - a.y) {}
  vet() {}
  vet operator-(vet oth) {
    vet c;
    c.x = this->x - oth.x;
    c.y = this->y - oth.y;
    return c;
  }
};

struct seg {
  point a, b;
  seg(point _a, point _b) : a(_a), b(_b) {}
  seg() {}
};

// produto vetorial
ld cross(vet u, vet v) { return u.x * v.y - u.y * v.x; }

// produto escalar
ld dot(vet u, vet v) { return u.x * v.x + u.y * v.y; }

// retorna verdadeiro se dois segmentos de reta se intersectam interiormente
bool intersect(seg x, seg y) {
  vet u(x.a, x.b), v(x.b, y.a), w(x.b, y.b);
  vet _u(y.a, y.b), _v(y.b, x.a), _w(y.b, x.b);
  return (cross(u, v) * cross(u, w) < -EPS) &&
         (cross(_u, _v) * cross(_u, _w) < -EPS);
}

// distancia ponto ponto
ld dpp(point a, point b) {
  vet u(a, b);
  return sqrtl(dot(u, u));
}

// distancia ponto segmento
ld dps(point a, seg x) {
  vet u(x.a, a), v(x.a, x.b);
  if (dot(v, v) < EPS) return dpp(x.a, a);
  ld lambda = dot(u, v) / dot(v, v);
  if (lambda < -EPS) return dpp(a, x.a);
  if (lambda > 1.) return dpp(a, x.b);
  return sqrtl(dot(u, u) - lambda * lambda * dot(v, v));
}

// distancia segmento segmento
ld dss(seg x, seg y) {
  if (intersect(x, y)) return 0;
  return min(dps(x.a, y), min(dps(x.b, y), min(dps(y.a, x), dps(y.b, x))));
}
