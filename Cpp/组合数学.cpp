//组合数预处理 / 杨辉三角 O(n^2)
//C[i][i] = C[i][0] = 1
//C[i][j] = C[i - 1][j] + C[i - 1][j - 1], 0 < j < i
const int maxc = 105;
ll C[maxc][maxc];
void calC() {
  for (int i = 0; i < maxc; i++) { C[i][i] = C[i][0] = 1; }
  for (int i = 2; i < maxc; i++) {
    for (int j = 1; j < i; j++) { C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M; }
  }
}
//求组合数不取模 O(n)
ll Com(ll n, ll m) {
  if (m > n) { return 0; }
  if (m > n - m) { m = n - m; }
  ll ret = 1;
  for (ll i = 0, j = 1; i < m; i++) {
    for (ret *= n - i; j <= m && ret % j == 0; j++) { ret /= j; }
  }
  return ret;
}
//求组合数取模
//p <= 1e6 预处理阶乘逆元 O(min(n, p)) + O(1)
ll fac[M + 5] = {1, 1}, invfac[M + 5] = {1, 1};
void initFac(ll p) {
  for (int i = 2; i < p; i++) {
    fac[i] = fac[i - 1] * i % p; invfac[i] = (-invfac[p % i] * (p / i) % p + p) % p;
  }
  for (int i = 2; i < p; i++) { invfac[i] = invfac[i] * invfac[i - 1] % p; }
}
ll Com(ll n, ll m, ll p) {
  return n < m ? 0 : fac[n] * invfac[n - m] % p * invfac[m] % p;
}
//p <= 1e9 在线求逆元 O(nlogp)
ll Com(ll n, ll m, ll p) {
  if (m > n) { return 0; }
  if (m > n - m) { m = n - m; }
  ll ret = 1;
  for (ll i = 1; i <= m; i++) {
    ll a = (n + i - m) % p, b = i % p;
    ret = ret * a % p * powMod(b, p - 2, p) % p;
  }
  return ret;
}
//Lucas定理
ll Lucas(ll n, ll m, ll p) {
  if (n < m) { return 0; }
  if (m == 0 && n == 0) { return 1; }
  return Com(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}
//第一类Stirling数 s(p, k)
//将p个物体排成k个非空循环排列的方法数
//s(p, k)的递推公式：s(p, k) = (p - 1) * s(p - 1, k) + s(p - 1, k - 1), 1 <= k <= p - 1
//边界条件：s(p, 0) = 0, p >= 1, s(p, p) = 1, p >= 0
const int maxs = 105;
ll S[maxs][maxs];
void calStir1() {
  S[0][0] = S[1][1] = 1;
  for (int i = 2; i < maxs; i++) {
    for (int j = 1; j <= i; j++) { S[i][j] = ((i - 1) * S[i - 1][j] + S[i - 1][j - 1]) % M; }
  }
}
//第二类Stirling数 S(p, k)
//将p个物体划分成k个非空的不可辨别的(可以理解为盒子没有编号)集合的方法数
//k! * S(p, k)是把p个人分进k间有差别(如被标有房号)的房间(无空房)的方法数
//S(p, k)的递推公式是：S(p, k) = k * S(p - 1, k) + S(p - 1, k - 1), 1 <= k <= p - 1
//边界条件：S(p, 0) = 0, p >= 1, S(p, p) = 1, p >= 0
const int maxs = 105;
ll S[maxs][maxs];
void calStir2() {
  S[0][0] = S[1][1] = 1;
  for (int i = 2; i < maxs; i++) {
    for (int j = 1; j <= i; j++) { S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % M; }
  }
}
//Bell数
//B(n)表示基数为n的集合的划分方法的数目
//B(0) = 1, B(n + 1) = sum(C(n, k) * B(k)), 0 <= k <= n
//每个贝尔数都是第二类Stirling数的和, 即B(n) = sum(S(n, k)), 1 <= k <= n
//Bell三角形
//a[0][0] = 1
//对于n >= 1, a[n][0] = a[n - 1][n - 1]
//对于m, n >= 1, a[n][m] = a[n][m - 1] + a[n - 1][m - 1]
//每行首项是贝尔数，每行之和是第二类Stirling数
//两个重要的同余性质:
//B(p + n) = B(n) + B(n + 1) (mod p)
//B(p^m + n) = m * B(n) + B(n + 1) (mod p)
//p是不大于100的素数, 这样, 我们可以通过上面的性质来计算Bell数模小于100的素数值
//Bell数模素数p的周期为: N(p) = ((p^p) - 1) / (p - 1)
const int maxb = 105;
ll T[maxb], B[maxb];
void calBell() {
  B[0] = B[1] = T[0] = 1;
  for (int i = 2; i < maxb; i++) {
    T[i - 1] = B[i - 1];
    for (int j = i - 2; j >= 0; j--) { T[j] = (T[j] + T[j + 1]) % M; }
    B[i] = T[0];
  }
}
//计算Bell(n)对999999598 = 2 × 13 × 5281 × 7283取模 O(P^2logP)
const int N = 7284, P = 999999598;
ll n; int p[5] = {2, 13, 5281, 7283}, B[2][N], T[N];
void init() {
  T[0] = T[1] = B[0][0] = 1; B[0][1] = 2;
  for (int i = 2, crt = 1; i < N; i++, crt ^= 1) {
    T[i] = B[crt][0] = B[crt ^ 1][i - 1];
    for (int j = 1; j <= i; j++) { B[crt][j] = (B[crt ^ 1][j - 1] + B[crt][j - 1]) % P; }
  }
}
int b[N], c[N], d[70];
int cal(ll n, int mod) {
  int len = 0;
  for (int i = 0; i <= mod; i++) { b[i] = T[i] % mod; }
  while (n) { d[len++] = n % mod; n /= mod; }
  for (int i = 1; i < len; i++) {
    for (int j = 1; j <= d[i]; j++) {
      for (int k = 0; k < mod; k++) { c[k] = (b[k] * i + b[k + 1]) % mod; }
      c[mod] = (c[0] + c[1]) % mod;
      for (int k = 0; k <= mod; k++) { b[k] = c[k]; }
    }
  }
  return c[d[0]];
}
ll bell(ll n) {
  if (n < N) { return T[n]; }
  ll t = 0;
  for (int i = 0; p[i]; i++) {
    t = (t + (P / p[i]) * powMod(P / p[i], p[i] - 2, p[i]) % P * cal(n, p[i]) % P) % P;
  }
  return t;
}
//卡特兰数 Catalan Number
//Cat(1) = 1, Cat(n) = (4n - 2) * Cat(n - 1) / (n + 1) = C(2n, n) / (n + 1) = C(2n, n) - C(2n, n - 1)
//从(0, 0)点走到(n, m)点且
//不经过对角线的方法数(x > y): C(n + m - 1, m) - C(n + m - 1, m - 1)
//不穿过对角线的方法数(x >= y): C(n + m, m) - C(n + m, m - 1)
//预处理卡特兰数
int a[105][105], b[105]; //大数, 长度
void Catalan() {
  int i, j, len, carry, temp;
  a[1][0] = b[1] = len = 1;
  for (i = 2; i <= 100; i++) {
    for (j = 0; j < len; j++) { //乘法
      a[i][j] = a[i - 1][j] * (4 * (i - 1) + 2);
    }
    carry = 0;
    for (j = 0; j < len; j++) { //处理相乘结果
      temp = a[i][j] + carry;
      a[i][j] = temp % 10;
      carry = temp / 10;
    }
    while (carry) { //进位处理
      a[i][len++] = carry % 10;
      carry /= 10;
    }
    carry = 0;
    for (j = len - 1; j >= 0; j--) { //除法
      temp = carry * 10 + a[i][j];
      a[i][j] = temp / (i + 1);
      carry = temp % (i + 1);
    }
    while (!a[i][len - 1]) { len--; } //高位零处理
    b[i] = len;
  }
}
//输出大数
void printCatalan(int n) {
  for (int i = b[n] - 1; i >= 0; i--) { printf("%d", a[n][i]); }
}
//各种情况下小球放盒子的方案数
//k个球 m个盒子 是否允许有空盒子 方案数
//不同 不同 是 m^k
//不同 不同 否 m!*Stirling2(k, m)
//不同 相同 是 ∑(m, i=1)Stirling2(k, i)
//不同 相同 否 Stirling2(k, m)
//相同 不同 是 C(m + k - 1, k)
//相同 不同 否 C(k - 1, m - 1)
//相同 相同 是 1/(1-x)(1-x^2)...(1-x^m)的x^k项的系数
//相同 相同 否 x^m/(1-x)(1-x^2)...(1-x^m)的x^k项的系数
//错排公式
//D(1) = 0, D(2) = 1, D(n) = (n - 1)(D(n - 2) + D(n - 1))
//扩展 Cayley 公式
//对于n个点, m个连通块的图, 假设每个连通块有a[i]个点, 那么用s - 1条边把它连通的方案数为n^(s-2)a[1]a[2]...a[m]
