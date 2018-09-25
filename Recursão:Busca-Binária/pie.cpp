#include <bits/stdc++.h>
using namespace std;

int n, f;
const double pi = atan(1.0) * 4;

int checking(long double num, long double arr[]) {
  int fr = 0;
  if (num == 0) return 0;
  for (int i = 0; i < n; i++) {
    fr += (int)(arr[i] / num);
  }
  if (fr >= f)
    return 1;
  else
    return 0;
}

long double binary_search(long double arr[]) {
  long double ini = 0, fim = arr[n - 1];

  while (fim - ini >= 1e-6) {
    long double mid = (ini + fim) / 2;
    if (checking(mid, arr) == 1) {
      ini = mid;
    } else
      fim = mid;
  }

  return ini;
}

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    scanf("%d %d", &n, &f);
    f++;

    int radii[n + 10];
    for (int i = 0; i < n; i++) {
      scanf("%d", &radii[i]);
    }

    long double volume[n + 10];
    sort(radii, radii + n);

    for (int i = 0; i < n; i++) {
      volume[i] = radii[i] * radii[i] * pi;
    }

    long double k = binary_search(volume);
    printf("%.4Lf\n", k);
  }
  return 0;
}
