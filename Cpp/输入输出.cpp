//关闭同步
ios_base::sync_with_stdio(false); cin.tie(NULL);
//输入一个非负整数
template<typename T> void read(T &x) {
  char c;
  while (!isdigit(c = getchar()));
  for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; }
}
//输入一个整数
template<typename T> void read(T &x) {
  char c; bool neg = false;
  while ((c = getchar()) != '-' && !isdigit(c));
  if (c == '-') { neg = true; c = getchar(); }
  for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; }
  if (neg) { x = -x; }
}
//输入一个数(int, long long, float, double)
template<typename T> void read(T &x) {
  char c; bool neg = false;
  while ((c = getchar()) != '-' && c != '.' && !isdigit(c));
  if (c == '-') { neg = true; c = getchar(); }
  for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; }
  if (c == ' ' || c == '\n' || c == EOF) { if (neg) { x = -x; } return; }
  for (T bit = 0.1; isdigit(c = getchar()); bit *= 0.1) { x += (c - '0') * bit; }
  if (neg) { x = -x; }
}
//空格作为分隔 读取一行的整数
const int BUFSIZE = 1 << 20;
char BUF[BUFSIZE];
void readln(int a[]) {
  int i = 0; gets(BUF);
  for (char *p = strtok(BUF, " "); p; p = strtok(NULL, " ")) { sscanf(p, "%d", &a[i++]); }
}
//输出一个正整数
template<typename T> void printn(T x) {
  if (x > 9) { printn(x / 10); }
  putchar(x % 10 + '0');
}
//配合fread
const int BUFSIZE = 1 << 20;
char BUF[BUFSIZE + 1], *S, *T; bool eof;
inline char gc() {
  if (S == T) {
    S = BUF; T = BUF + fread(BUF, 1, BUFSIZE, stdin);
    if (S == T) { eof = true; return EOF; }
  }
  return *S++;
}
template<typename T> void ni(T &x) {
  char c; bool neg = false; x = 0;
  while ((c = gc()) != '-' && !isdigit(c));
  if (eof) { return; }
  if (c == '-') { neg = true; c = gc(); }
  for (; isdigit(c); c = gc()) { x = x * 10 + c - '0'; }
  if (neg) { x = -x; }
}
void nd(double &x) {
  char c; bool neg = false; x = 0;
  while ((c = gc()) != '-' && !isdigit(c));
  if (eof) { return; }
  if (c == '-') { neg = true; c = gc(); }
  for (; isdigit(c); c = gc()) { x = x * 10 + c - '0'; }
  if (c == '.') { for (double bit = 0.1; isdigit(c = gc()); bit *= 0.1) { x += (c - '0') * bit; } }
  if (neg) { x = -x; }
}
void ns(char *s) {
  char c;
  while (isspace(c = gc()));
  if (eof) { return; }
  for (; !isspace(c); c = gc()) { *s++ = c; } *s = 0;
}
