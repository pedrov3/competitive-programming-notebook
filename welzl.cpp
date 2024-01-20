const double EPS = 1e-15;

struct point {
  double x, y;

  point(double _x, double _y) : x(_x), y(_y) {}

  point() {}
};

struct circle {
  point c;
  double r;

  circle(point _c, double _r) : c(_c), r(_r) {}

  circle() {}
};

double dist(const point &a, const point &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrtl(dx * dx + dy * dy);
}

bool lte(double a, double b) { return b - a >= -EPS; }

bool is_inside(const circle &c, const point &p) {
  return lte(dist(c.c, p), c.r);
}

circle circle_from(const point &A, const point &B) {
  point c = {(A.x + B.x) / 2.0L, (A.y + B.y) / 2.0L};
  return {c, dist(c, A)};
}

// A partir da equação (x - a)^2 + (y - b)^2 = r^2
// Encontrar a, b, resolvendo um sistema linear usandos os pontos dados.
circle circle_from(point &p1, point &p2, point &p3) {
  double a = 2 * (-p1.x + p2.x);
  double b = 2 * (-p1.y + p2.y);
  double c = 2 * (-p2.x + p3.x);
  double d = 2 * (-p2.y + p3.y);
  double r1 = -(p1.x * p1.x - p2.x * p2.x + p1.y * p1.y - p2.y * p2.y);
  double r2 = -(p2.x * p2.x - p3.x * p3.x + p2.y * p2.y - p3.y * p3.y);
  double det = a * d - b * c;
  double cx = (d * r1 - b * r2) / det;
  double cy = (-c * r1 + a * r2) / det;

  point center{cx, cy};
  double radius = dist(center, p1);
  return {center, radius};
}

circle min_circle_trivial(vector<point> &P) {
  if (P.empty()) {
    return {{0, 0}, 0};
  } else if (P.size() == 1) {
    return {P[0], 0};
  } else if (P.size() == 2) {
    return circle_from(P[0], P[1]);
  } else {
    return circle_from(P[0], P[1], P[2]);
  }
}

mt19937 rnd((int)chrono::steady_clock::now().time_since_epoch().count());

int gen(int a, int b) {
  uniform_int_distribution<int> dist(a, b);
  return dist(rnd);
}

circle welzl(vector<point> &pontos, vector<point> r, int n) {
  if (n == 0 || r.size() == 3) {
    return min_circle_trivial(r);
  }
  // Escolher um ponto aleatoriamente
  int idx = gen(0, n - 1);
  point p = pontos[idx];

  // Coloca no fim e desconsidera
  swap(pontos[idx], pontos[n - 1]);

  circle d = welzl(pontos, r, n - 1);
  if (is_inside(d, p)) {
    return d;
  }
  r.push_back(p);
  return welzl(pontos, r, n - 1);
}

circle welzl(vector<point> &pontos) { return welzl(pontos, {}, pontos.size()); }
