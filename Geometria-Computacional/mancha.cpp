#include <math.h>
#include <stdio.h>
#include <vector>
#define MAX 112345
using namespace std;

vector<int> adj[MAX];
int vis[MAX], n, ans;

int dfs(int a) {
  int cnt = 1;
  for (int i = 0; i < adj[a].size(); i++) {
    if (!vis[adj[a][i]]) {
      vis[adj[a][i]] = 1;
      int cnt_adj = dfs(adj[a][i]);
      cnt += cnt_adj;

      int diff = abs(cnt_adj - (n - cnt_adj));
      if (diff < ans) ans = diff;
    }
  }
  return cnt;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ans = n;
  dfs(1);
  printf("%d\n", ans);
  return 0;
}