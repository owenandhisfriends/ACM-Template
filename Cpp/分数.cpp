//分数类
struct Frac {
  ll a, b; //分子, 分母
  Frac(const ll &_a = 0, const ll &_b = 1): a(_a), b(_b) {
    if (b < 0) { a = -a; b = -b; }
    ll t = __gcd(a, b); a /= t, b /= t;
  }
  Frac operator-()const { return Frac(-a, b); }
  Frac operator+(const Frac &r)const { return Frac(a * r.b + r.a * b, b * r.b); }
  Frac operator-(const Frac &r)const { return Frac(a * r.b - r.a * b, b * r.b); }
  Frac operator*(const Frac &r)const { return Frac(a * r.a, b * r.b); }
  Frac operator/(const Frac &r)const { return Frac(a * r.b, b * r.a); }
  Frac &operator+=(const Frac &r) { return *this = *this + r; }
  Frac &operator-=(const Frac &r) { return *this = *this - r; }
  Frac &operator*=(const Frac &r) { return *this = *this * r; }
  Frac &operator/=(const Frac &r) { return *this = *this / r; }
  bool operator<(const Frac &r)const { return a * r.b < r.a * b; }
  bool operator>(const Frac &r)const { return a * r.b > r.a * b; }
  bool operator==(const Frac &r)const { return a * r.b == r.a * b; }
  bool operator!=(const Frac &r)const { return a * r.b != r.a * b; }
  bool operator<=(const Frac &r)const { return a * r.b <= r.a * b; }
  bool operator>=(const Frac &r)const { return a * r.b >= r.a * b; }
  void print() { if (b == 1) { printf("%I64d", a); } else { printf("%I64d/%I64d", a, b); } }
  friend ostream &operator<<(ostream &out, const Frac &r) {
    if (r.b == 1) { out << r.a; } else { out << r.a << '/' << r.b; } return out;
  }
};
