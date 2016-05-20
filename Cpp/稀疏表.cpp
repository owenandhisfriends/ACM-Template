//稀疏表 Sparse Table
//一维RMQ 预处理O(nlogn) 查询O(1)
//返回最大值 下标从1开始 修改即可返回下标
int p[N] = { -1}, dp[N][20];
void initRMQ() {
  for (int i = 1; i <= n; i++) { p[i] = p[i - 1] + !(i & (i - 1)); dp[i][0] = a[i]; }
  for (int j = 1; j <= p[n]; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      dp[i][j] = dp[i][j - 1] > dp[i + (1 << (j - 1))][j - 1] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
    }
  }
}
inline int query(int l, int r) {
  int k = p[r - l + 1];
  return dp[l][k] > dp[r - (1 << k) + 1][k] ? dp[l][k] : dp[r - (1 << k) + 1][k];
}
//二维RMQ 预处理O(nmlognlogm) 查询O(1) 下标从1开始
int p[N] = { -1}, dp[N][N][9][9];
void initRMQ() {
  for (int i = 1; i <= n; i++) {
    p[i] = p[i - 1] + !(i & (i - 1));
    for (int j = 1; j <= n; j++) { dp[i][j][0][0] = a[i][j]; }
  }
  for (int ii = 0; ii <= p[n]; ii++) {
    for (int jj = 0; jj <= p[m]; jj++) {
      if (ii + jj) {
        for (int i = 1; i + (1 << ii) - 1 <= n; i++) {
          for (int j = 1; j + (1 << jj) - 1 <= m; j++) {
            if (ii) { dp[i][j][ii][jj] = max(dp[i][j][ii - 1][jj], dp[i + (1 << (ii - 1))][j][ii - 1][jj]); }
            else { dp[i][j][ii][jj] = max(dp[i][j][ii][jj - 1], dp[i][j + (1 << (jj - 1))][ii][jj - 1]); }
          }
        }
      }
    }
  }
}
inline int query(int x1, int y1, int x2, int y2) {
  int k1 = p[x2 - x1 + 1], k2 = p[y2 - y1 + 1]; x2 -= (1 << k1) - 1; y2 -= (1 << k2) - 1;
  return max(max(dp[x1][y1][k1][k2], dp[x1][y2][k1][k2]), max(dp[x2][y1][k1][k2], dp[x2][y2][k1][k2]));
}
