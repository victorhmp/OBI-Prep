// Calcula Fibonacci até o n-ésimo termo
// Consumo de tempo O(2^n)

#include <iostream>

using namespace std;

int fibo(int n) {
  if (n <= 1) return n;
  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  int n = 0;
  cin >> n;

  cout << fibo(n) << endl;
}