// OBI 2007 - N1 Fase 2
// Busca binária iterativa
// O (n log n)

#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

int n, k, p, sand[MAXN];

int buscab(int maxi) {
  int ini = 0, fim = maxi, ans = 0;

  while (ini <= fim) {
    int mid = (ini + fim) / 2;

    int qtd = 0;
    for (int i = 0; i < k; i++) {
      qtd += sand[i] / mid;
      if (qtd >= n) {
        ans = max(mid, ans);
        ini = mid + 1;
      }
    }

    if (qtd < n) fim = mid - 1;
  }

  return ans;
}

int main() {
  scanf("%d %d", &n, &k);

  for (int i = 0; i < k; i++) {
    scanf("%d", &sand[i]);

    p = max(p, sand[i]);
  }

  printf("%d\n", buscab(p));
  return 0;
}
