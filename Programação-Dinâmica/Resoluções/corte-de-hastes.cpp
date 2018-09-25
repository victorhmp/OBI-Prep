#include <algorithm>
#include <iostream>

using namespace std;

int p[11234], r[11234], n;

int solve(int p[], int n) {
  int q;
  r[0] = 0;
  for (int j = 1; j <= n; j++) {
    q = -112345;
    for (int i = 1; i <= j; i++) {
      q = max(q, (p[i] + r[j - i]));
    }
    r[j] = q;
  }

  return q;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];

  cout << solve(p, n) << endl;
  return 0;
}