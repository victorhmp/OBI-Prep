// Knapsack Problem naive implementation (No DP)
// O(2^n)

#include <algorithm>
#include <cstdio>
using namespace std;

int val[110], weight[110];
int cap, n;  // n<=100

// recursive fuction to return maximum value that can be put in a knapsack of
// capacity = cap
int knapsack(int cap, int n) {
  // base case
  if (n == 0 || cap <= 0) return 0;

  if (weight[n - 1] > cap)
    return knapsack(cap, n - 1);

  else {
    int including = val[n - 1] + knapsack(cap - weight[n - 1], n - 1);
    int not_including = knapsack(cap, n - 1);

    return max(including, not_including);
  }
}

int main() {
  scanf("%d %d", &n, &cap);
  for (int i = 0; i < n; i++) scanf("%d %d", &val[i], &weight[i]);

  printf("%d\n", knapsack(cap, n));

  return 0;
}
