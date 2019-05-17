#include <algorithm>
#include <iostream>

using namespace std;

int s1[1010], s2[1010], tab[1123][1123];
int n;

// int lcs(int a, int b) {
//   if (tab[a][b] >= 0) return tab[a][b];
//   if (!a || !b) return tab[a][b] = 0;
//   if (s1[a] == s2[b]) return (lcs(a - 1, b - 1) + 1);

//   return tab[a][b] = max(lcs(a - 1, b), lcs(a, b - 1));
// }

int lcs(int a, int b) {
  if (tab[a][b] >= 0) return tab[a][b];

  if (!a || !b) return tab[a][b] = 0;

  if (s1[a] == s2[b]) return 1 + lcs(a - 1, b - 1);

  return tab[a][b] = max(lcs(a - 1, b), lcs(a, b - 1));
}

// int lcs(int m, int n) {
//   for (int i = 0; i <= m; i++) tab[i][0] = 0;
//   for (int j = 0; j <= n; j++) tab[0][j] = 0;

//   for (int i = 1; i <= m; i++) {
//     for (int j = 1; j <= n; j++) {
//       if (s1[i] == s2[j])
//         tab[i][j] = tab[i - 1][j - 1] + 1;
//       else
//         tab[i][j] = max(tab[i - 1][j], tab[i][j - 1]);
//     }
//   }

//   return tab[m][n];
// }

int main() {
  memset(tab, -1, sizeof(tab));

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s1[i];
    s2[i] = s1[i];
  }

  sort(s2, s2 + n);
  cout << lcs(n - 1, n - 1) << endl;

  return 0;
}