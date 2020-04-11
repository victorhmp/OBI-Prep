#include <iostream>

#define MAXR 112
#define MAXK 21

using namespace std;

int r, k;
int dp[MAXK][MAXR][MAXR];

int count_combinations(int products_left, int value_left, int last_value) {
  int current_state = dp[products_left][value_left][last_value];

  if (current_state != -1) return current_state;
  if (products_left <= 0 && value_left <= 0)
    return dp[products_left][value_left][last_value] = 1;
  if (products_left <= 0 || value_left <= 0)
    return dp[products_left][value_left][last_value] = 0;

  int answer = 0;

  for (int i = last_value + 1; i <= value_left; i++) {
    answer += count_combinations(products_left - 1, value_left - i, i);
  }

  return dp[products_left][value_left][last_value] = answer;
}

int main(void) {
  cin >> r >> k;

  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= r; j++) {
      for (int z = 0; z <= r; z++) {
        dp[i][j][z] = -1;
      }
    }
  }

  int answer = count_combinations(k, r, 0);

  cout << answer << endl;
  return 0;
}