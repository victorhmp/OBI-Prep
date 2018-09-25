// Programa que calcula o número mínimo de multilicações
// escalares necessárias para calcular o produto de n matrizes
// de tamanhos p[0...n] tal que a matriz A[i] tem dimensões
// p[i-1] p[i].
// Consumo de tempo O(n^3)

#include <iostream>
using namespace std;

long long int m[112][112];
int p[112];

long long int min_multiplications(int p[], int n) {
  for (int i = 1; i <= n; i++) {
    m[i][i] = 0;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      int j = i + l - 1;
      m[i][j] = 11234567;
      for (int k = i; k <= j - 1; k++) {
        long long int q = m[i][k] + p[i - 1] * p[k] * p[j] + m[k + 1][j];
        if (q < m[i][j]) {
          m[i][j] = q;
        }
      }
    }
  }

  return m[1][n];
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> p[i];
  }

  cout << min_multiplications(p, n) << endl;

  return 0;
}