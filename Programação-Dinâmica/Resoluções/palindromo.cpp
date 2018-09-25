// Problema "Palíndromo" -> OBI 2017 - F1PU
// Solução em O(n^2)

#include <cstring>
#include <iostream>
using namespace std;

#define MAX 2001

int dp[MAX];
int palindrome[MAX][MAX];
string input;

int check_palindrome(int a, int b) {
  // Já foi processado
  if (palindrome[a][b] != -1) return palindrome[a][b];

  // Caso base (1 caracter)
  if (a == b) return palindrome[a][b] = 1;

  // Verificações da definição de palíndromo dada pelo problema
  if (a == b - 1) return palindrome[a][b] = (input[a] == input[b]);
  if (input[a] != input[b]) return palindrome[a][b] = 0;  // Não é um palíndromo

  // Checar recursivamente a substring input[a+1, b-1]
  return palindrome[a][b] = check_palindrome(a + 1, b - 1);
}

int min_partition(int k) {
  // Se dp[k] != -1, já sei o resultado não preciso calcular novamente.
  if (dp[k] != -1) return dp[k];

  // Se input[0, k] é um palíndromo
  // então só preciso de 1 partição
  if (check_palindrome(0, k) == 1) return dp[k] = 1;

  // Se não for, iremos resolver utilizando os problemas anteriores.
  int min = MAX;
  for (int i = k; i > 0; i--) {
    if (check_palindrome(i, k) == 1) {
      int val = min_partition(i - 1);
      if (val + 1 < min) min = val + 1;
    }
  }

  return dp[k] = min;
  // dp[k] = min{ 1 + dp[k]  |  i  ∈  [0, k]  e  palindrome[i+1][k] = 1}
}

int main() {
  int N, res;

  // Inicializo as matrizes com -1
  memset(dp, -1, sizeof dp);
  memset(palindrome, -1, sizeof palindrome);

  cin >> N >> input;
  cout << min_partition(N - 1) << endl;

  return 0;
}