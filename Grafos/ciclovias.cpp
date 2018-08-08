#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

vector<int> neighbors[MAXN];

int n, m, resp[MAXN], max_sufix[MAXN];

int main() {
  cin >> n >> m;

  // No começo, o maior caminho que começa em cada vértice
  // tem tamanho 1: o próprio vértice
  for (int i = 1; i <= n; i++) resp[i] = 1;

  // Construo as listas de adjacência
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    neighbors[b].push_back(a);
    neighbors[a].push_back(b);
  }

  // Ordeno os vizinhos de cada vértice
  for (int i = 1; i <= n; i++) sort(neighbors[i].begin(), neighbors[i].end());

  // Processo os vértices do maior para o menor
  for (int i = n; i >= 1; i--) {
    // Primeiro, calculo o maior caminho de cada sufixo
    max_sufix[neighbors[i].size()] = 0;
    for (int j = neighbors[i].size() - 1; j >= 0; j--) {
      int v = neighbors[i][j];

      max_sufix[j] = max(resp[v], max_sufix[j + 1]);
    }

    // Depois o maior caminho de cada vizinho cujo segundo vértice é i
    for (int j = 0; j < neighbors[i].size(); j++) {
      int v = neighbors[i][j];

      // Atualizo resp[v] para cada vizinho
      resp[v] = max(resp[v], 2 + max_sufix[j + 1]);
    }
  }

  // Por fim, imprimo a resposta de cada vértice
  for (int i = 1; i <= n; i++) cout << resp[i] << " \n"[i == n];

  return 0;
}