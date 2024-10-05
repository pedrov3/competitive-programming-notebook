struct pt {
  ll x, y;
  pt operator+(pt p) { return {x + p.x, y + p.y}; }
  pt operator-(pt p) { return {x - p.x, y - p.y}; }
  pt operator*(ll p) { return {x * p, y * p}; }
};

int ccw(pt p, pt q, pt o) {
  ll tmp = (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
  return (tmp >= 0) - (tmp <= 0);
}

vector<pt> ski(vector<pt> &a, vector<pt> &b) {
  vector<pt> retval;
  ll minx1 = oo, miny1 = oo, minx2 = oo, miny2 = oo;
  int idx1 = 0, idx2 = 0, i1 = 0, i2 = 0;
  pt orig{0, 0};
  for (int i = 0; i < a.size(); i++) {
    if (miny1 > a[i].y) {
      miny1 = a[i].y;
      minx1 = a[i].x;
    } else if (miny1 == a[i].y) {
      chmin(minx1, a[i].x);
    }
  }
  for (int i = 0; i < b.size(); i++) {
    if (miny2 > b[i].y) {
      miny2 = b[i].y;
      minx2 = b[i].x;
    } else if (miny2 == b[i].y) {
      chmin(minx2, b[i].x);
    }
  }

  while (a[idx1].x != minx1 || a[idx1].y != miny1) idx1++;
  while (b[idx2].x != minx2 || b[idx2].y != miny2) idx2++;

  while (i1 < a.size() || i2 < b.size()) {
    int j1 = (i1 + idx1) % a.size();
    int j2 = (i2 + idx2) % b.size();
    pt vt1 = a[(j1 + 1) % a.size()] - a[j1];
    pt vt2 = b[(j2 + 1) % b.size()] - b[j2];
    int fl = 0;
    retval.push_back(a[j1] + b[j2]);
    if (i1 == a.size())
      fl = -1;
    else if (i2 == b.size())
      fl = 1;
    else {
      fl = ccw(vt1, vt2, orig);
    }
    if (fl >= 0) i1++;
    if (fl <= 0) i2++;
  }
  return retval;
}

bool is_inside(vector<pt> &v, pt qry) {
  int sz = v.size() - 2;
  if (qry.y < v[0].y) return false;
  int l = 0;
  int r = sz + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    int t = ccw(qry, v[mid + 1], v[0]);
    if (t == -1) l = mid + 1;
    else r = mid;
  }
  if (l == 0 && ccw(qry, v[1], v[0]) == 1) return false;
  if (l == sz + 1 && ccw(qry, v[sz + 1], v[0]) == -1) return false;
  if (l == sz + 1) l--;
  if (l == 0) l++;
  if (ccw(qry, v[l + 1], v[l]) <= 0) return true;
  return false;
}
