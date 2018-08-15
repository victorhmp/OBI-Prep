#include <cstdio>
#include <iostream>

using namespace std;

#define MAXN 112345

int N;
int max_total = -1, bets[MAXN];

void kadane(int v[], int n) {
  int max_atual = 0;
  for (int i = 0; i < n; i++) {
    max_atual = max_atual + v[i];
    if (max_atual < 0) {
      max_atual = 0;
    }
    if (max_atual > max_total) {
      max_total = max_atual;
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> bets[i];
  }

  kadane(bets, N);

  max_total > 0
      ? cout << "The maximum winning streak is " << max_total << "." << endl
      : cout << "Losing streak." << endl;
}