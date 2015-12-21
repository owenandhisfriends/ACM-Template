//iostream关闭同步
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);
//输入一个非负整数
template<typename T> inline void getI(T &x) {
  char c; x = 0;
  while ((c = getchar()) < '0' || c > '9');
  while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
}
//输入一个整数
template<typename T> inline bool getI(T &x) {
  char c; T sign = 1; x = 0;
  if (c = getchar(), c == EOF) { return false; }
  while (c != '-' && (c < '0' || c > '9')) { c = getchar(); };
  if (c == '-') { sign = -1; c = getchar(); }
  while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
  x *= sign; return true;
}
//输入一个数(int, long long, float, double)
template<typename T> bool getN(T &x) {
  char c; T sign = 1; T bit = 0.1; x = 0;
  if (c = getchar(), c == EOF) { return false; }
  while (c != '-' && c != '.' && (c < '0' || c > '9')) { c = getchar(); }
  if (c == '-') { sign = -1; c = getchar(); }
  while (c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
  if (c == ' ' || c == '\n') { x *= sign; return true; }
  while (c = getchar(), c >= '0' && c <= '9') { x += (c - '0') * bit, bit /= 10.0; }
  x *= sign; return true;
}
//空格作为分隔 读取一行的整数
void getL(int a[]) {
  int i = 0;
  gets(buf);
  for (char *p = strtok(buf, " "); p; p = strtok(NULL, " ")) {
    sscanf(p, "%d", &a[i++]);
  }
}
//输出一个整数
template<typename T> inline void printI(T x) {
  if (x > 9) { printInt(x / 10); }
  putchar(x % 10 + '0');
}
