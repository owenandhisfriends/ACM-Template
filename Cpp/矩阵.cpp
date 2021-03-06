//矩阵类
template<typename T> struct mat {
  vector<T> a; int h, w;
  mat(): a(), h(), w() {}
  mat(const mat &v): a(v.a), h(v.h), w(v.w) {}
  mat(const int &_h, const int &_w): a(_h * _w), h(_h), w(_w) { }
  void init() { a.clear(); a.resize(h * w); }
  static mat e(const int &_h, const int &_w) {
    mat ret(_h, _w);
    for (int i = 0, n = min(_h, _w); i < n; i++) { ret[i][i] = 1; }
    return ret;
  }
  static mat e(const mat &b) { return e(b.h, b.w); }
  T *operator[](const int &v) { return &a[v * w]; }
  const T *operator[](const int &v)const { return &a[v * w]; }
  mat &operator+=(const mat &b) {
    for (int i = 0, n = h * w; i < n; i++) { a[i] += b.a[i]; }
    return *this;
  }
  mat &operator-=(const mat &b) { return *this += -b; }
  mat &operator*=(const mat &b) {
    mat c(h, b.w);
    for (int i = 0; i < h; i++) {
      for (int k = 0; k < w; k++) {
        const T &tmp = (*this)[i][k];
        if (isZero(tmp)) { continue; }
        for (int j = 0; j < b.w; j++) { c[i][j] = (c[i][j] + tmp * b[k][j])/*%M*/; }
      }
    }
    swap(a, c.a); h = c.h; w = c.w; return *this;
  }
  mat operator-()const {
    mat ret(*this);
    for (int i = 0, n = h * w; i < n; i++) { ret.a[i] = -ret.a[i]; }
    return ret;
  }
  mat operator+(const mat &b)const { return mat(*this) += b; }
  mat operator-(const mat &b)const { return mat(*this) -= b; }
  mat operator*(const mat &b)const { return mat(*this) *= b; }
  mat operator^(const ll &v)const {
    mat ret(e(*this)), t(*this);
    for (ll b = v; b; b >>= 1) { if (b & 1) { ret *= t; } t *= t; }
    return ret;
  }
  bool operator==(const mat &b)const {
    if (h != b.h || w != b.w) { return false; }
    for (int i = 0, n = h * w; i < n; i++) { if (!isZero(a[i] - b.a[i])) { return false; } }
    return true;
  }
  bool operator!=(const mat &b)const { return !(*this == b); }
  T abs(const T &v)const { return v < 0 ? -v : v; }
  bool isZero(const T &v)const { return abs(v) < 1e-9; }
  void input() { for (int i = 0, n = h * w; i < n; i++) { scanf("%I64d", &a[i]); } }
  void print()const {
    for (int i = 0, n = h * w; i < n; i++) { printf("%I64d%c", a[i], i % w == w - 1 ? '\n' : ' '); }
  }
  mat trans()const {
    mat ret(w, h);
    for (int i = 0; i < w; i++) { for (int j = 0; j < h; j++) { ret[i][j] = a[j][i]; } }
    return ret;
  }
  //求逆矩阵 限double 可逆则返回true 结果在参数v中
  bool inv(mat &v)const {
    if (h != w) { return false; }
    int is[N], js[N]; v = *this;
    for (int k = 0; k < h; k++) {
      double t = 0;
      for (int i = k; i < h; i++) {
        for (int j = k; j < h; j++) {
          if (abs(v[i][j]) > t) { t = abs(v[is[k] = i][js[k] = j]); }
        }
      }
      if (isZero(t)) { return false; }
      if (is[k] != k) { for (int j = 0; j < h; j++) { swap(v[k][j], v[is[k]][j]); } }
      if (js[k] != k) { for (int i = 0; i < h; i++) { swap(v[i][k], v[i][js[k]]); } }
      v[k][k] = 1.0 / v[k][k];
      for (int j = 0; j < h; j++) { if (j != k) { v[k][j] *= v[k][k]; } }
      for (int i = 0; i < h; i++) {
        if (i != k) { for (int j = 0; j < h; j++) { if (j != k) { v[i][j] -= v[i][k] * v[k][j]; } } }
      }
      for (int i = 0; i < h; i++) { if (i != k) { v[i][k] *= -v[k][k]; } }
    }
    for (int k = h - 1; k >= 0; k--) {
      for (int j = 0; j < h; j++) { if (js[k] != k) { swap(v[k][j], v[js[k]][j]); } }
      for (int i = 0; i < h; i++) { if (is[k] != k) { swap(v[i][k], v[i][is[k]]); } }
    }
    return true;
  }
  //求行列式模M 需逆元
  ll detmod()const {
    if (h != w) { return 0; }
    ll ret = 1; mat c(*this);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < h; j++) { c[i][j] %= M; }
    }
    for (int i = 0; i < h; i++) {
      for (int j = i + 1; j < h; j++) {
        for (; c[j][i]; ret = -ret) {
          ll t = c[i][i] / c[j][i];
          for (int k = i; k < h; k++) {
            c[i][k] = (c[i][k] - c[j][k] * t) % M;
            swap(c[j][k], c[i][k]);
          }
        }
      }
      if (c[i][i] == 0) { return 0; }
      ret = ret * c[i][i] % M;
    }
    return (ret + M) % M;
  }
  //求行列式 限double
  double det()const {
    if (h != w) { return 0; }
    int sign = 0; double ret = 1.0; mat c(*this);
    for (int i = 0, j, k; i < h; i++) {
      if (isZero(c[i][i])) {
        for (j = i + 1; j < h && isZero(c[j][i]); j++);
        if (j == h) { return 0; }
        for (k = i; k < h; k++) { swap(c[i][k], c[j][k]); }
        sign++;
      }
      ret *= c[i][i];
      for (k = i + 1; k < h; k++) { c[i][k] /= c[i][i]; }
      for (j = i + 1; j < h; j++) { for (k = i + 1; k < h; k++) { c[j][k] -= c[j][i] * c[i][k]; } }
    }
    return sign & 1 ? -ret : ret;
  }
};
//short ver.
struct mat {
  ll m[N][N]; int h, w;
  mat(int _h = 0, int _w = 0): h(_h), w(_w) { memset(m, 0, sizeof(m)); }
  mat(const mat &v): h(v.h), w(v.w) { memcpy(m, v.m, sizeof(m)); }
  mat &operator=(const mat &v) { h = v.h; w = v.w; memcpy(m, v.m, sizeof(m)); return *this; }
};
mat mul(const mat &a, const mat &b) {
  mat c(a.h, b.w);
  for (int i = 0; i < a.h; i++) {
    for (int k = 0; k < a.w; k++) {
      if (!a.m[i][k]) { continue; }
      for (int j = 0; j < b.w; j++) { c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % M; }
    }
  }
  return c;
}
mat pow(const mat &a, ll b) {
  mat ret(a.h, a.w), t(a);
  for (int i = 0; i < min(a.h, a.w); i++) { ret.m[i][i] = 1; }
  for (; b; b >>= 1) { if (b & 1) { ret = mul(ret, t); } t = mul(t, t); }
  return ret;
}
