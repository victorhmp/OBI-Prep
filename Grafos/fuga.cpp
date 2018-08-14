// Problema "Fuga" da OBI2018-P2F2

#include <stdio.h>
#include <string.h>

char grid[112][112];
int n, m;
int xi, yi, xf, yf;

int dx[4] = {2, -2, 0, 0};
int dy[4] = {0, 0, 2, -2};

int best = 0;

// Função que resolve recursivamente o problema, de forma exaustiva.
// Não é um problema devido aos limites do problema
void solve(int x, int y, int k) {
  // Caso base da recursão
  // Chegar na saída e ver se o número de movimentos necessários é o máximo
  if (x == xf && y == yf && k > best)
    best = k;
  else {
    // Testar os quatro possíveis direções para o
    // próximo passo no caminho
    for (int i = 0; i < 4; i++) {
      // Se a posição está livre para o percorrer
      if (grid[x + dx[i]][y + dy[i]] == '.') {
        // Marco essa posição como visitada
        grid[x + dx[i]][y + dy[i]] = 'V';

        // Chamo a função novamente, partindo da posição marcada
        // sinalizando que um movimento foi feito
        solve(x + dx[i], y + dy[i], k + 1);

        // Volto a posição analisada para o valor original (livre)
        grid[x + dx[i]][y + dy[i]] = '.';
      }
    }
  }
}

int main() {
  scanf("%d %d %d %d %d %d", &n, &m, &xi, &yi, &xf, &yf);

  // Inicializo o grid com '#'
  memset(grid, '#', sizeof(grid));

  // Marco as posições sem armários com '.'
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (i % 2 != 0 || j % 2 != 0) grid[i][j] = '.';

  // Marcar entrada como ocupada para evitar que ela seja barrada
  grid[xi][yi] = '#';

  // Chamo a função que resolve o problema partindo da entrada
  solve(xi, yi, 1);

  // Ajuste para obter a resposta
  int resp = (2 * best) - 1;
  printf("%d\n", resp);

  return 0;
}