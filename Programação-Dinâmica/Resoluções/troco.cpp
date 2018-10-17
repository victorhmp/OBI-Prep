#include <cstdio>

char resposta = 'N';
int v, m;
bool matriz[1010][100010];
int moeda[1010];

void busca(int coin, int soma) {
  if (matriz[coin][soma]) return;

  matriz[coin][soma] = 1;

  if (soma == v) {
    resposta = 'S';
    return;
  }

  if (coin > m || soma > v) return;

  busca(coin + 1, soma + moeda[coin]);
  busca(coin + 1, soma);
}

int main() {
  scanf("%d %d", &v, &m);  // lemos os valores de v e m

  for (int i = 1; i <= m; i++) scanf("%d", &moeda[i]);

  busca(1, 0);

  printf("%c\n", resposta);

  return 0;
}