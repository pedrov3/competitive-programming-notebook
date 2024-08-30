ostream& operator<<(ostream& out, __int128 x) {
  if (x == 0) return out << 0;
  string s;
  bool sig = x < 0;
  x = x < 0 ? -x : x;
  while (x > 0) s += x % 10 + '0', x /= 10;
  if (sig) s += '-';
  reverse(all(s));
  return out << s;
}

istream& operator>>(istream& in, __int128& x) {
  char c, neg = 0;
  while (isspace(c = in.get()))
    ;
  if (!isdigit(c))
    neg = (c == '-'), x = 0;
  else
    x = c - '0';
  while (isdigit(c = in.get())) x = (x << 3) + (x << 1) - '0' + c;
  x = neg ? -x : x;
  return in;
}
