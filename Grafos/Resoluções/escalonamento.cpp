#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define MAXN 50010
using namespace std;

int nodes, edges;
int grau[MAXN];
vector<int> neighbors[MAXN];
vector<int> resp;
priority_queue<int, vector<int>, greater<int> > heap;

int main() {
  scanf("%d %d", &nodes, &edges);

  memset(grau, 0, sizeof grau);

  for (int i = 1; i <= edges; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    a++;
    b++;
    grau[b]++;
    neighbors[a].push_back(b);
  }

  for (int i = 1; i <= nodes; i++)
    if (!grau[i]) heap.push(i);

  int count = 0;
  while (!heap.empty()) {
    count++;
    int len = neighbors[heap.top()].size();
    int current = heap.top();
    heap.pop();

    for (int i = 0; i < len; i++) {
      grau[neighbors[current][i]]--;
      if (!grau[neighbors[current][i]]) heap.push(neighbors[current][i]);
    }

    resp.push_back(current);
  }

  if (count < nodes)
    printf("*\n");
  else
    for (int i = 0; i < nodes; i++) printf("%d\n", resp[i] - 1);

  return 0;
}