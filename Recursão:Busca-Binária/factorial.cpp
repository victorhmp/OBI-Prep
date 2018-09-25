// Simple factorial recursion
// O(2^(n log n))

#include <cstdio>
#include <iostream>

using namespace std;

long factorial(long n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}

long n;

int main() {
  cin >> n;
  cout << factorial(n) << endl;
}
