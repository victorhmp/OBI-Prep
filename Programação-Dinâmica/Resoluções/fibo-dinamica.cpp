// Calcula Fibonacci até o n-ésimo termo
// Consumo de tempo (e espaço) O(n)

#include <iostream>

using namespace std;

long long int fibo_seq[110];
int n;

int fibo(int n) {
  fibo_seq[0] = 0;
  fibo_seq[1] = 1;
  for (int i = 2; i <= n; i++) {
    fibo_seq[i] = fibo_seq[i - 1] + fibo_seq[i - 2];
  }

  return fibo_seq[n];
}

int main() {
  cin >> n;

  cout << fibo(n) << endl;
}