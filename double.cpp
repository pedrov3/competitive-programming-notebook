typedef long double ld;

const ld EPS = 1e-9;

bool equal(ld x, ld y) { return fabs(x - y) < EPS; }

bool lt(ld x, ld y) { return x - y < -EPS; }

bool gt(ld x, ld y) { return x - y > EPS; }

bool gte(ld x, ld y) { return x - y > -EPS; }

bool lte(ld x, ld y) { return x - y < EPS; }
