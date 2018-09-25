// Gincana - OBI2016 - PJF2

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll euclides(ll a, ll b) {
  if (a < b) swap(a, b);

  if (b == 0) return a;

  return euclides(b, a % b);
}

ll n, m, resp;

int main() {
  cin >> n >> m;

  for (ll i = m; i >= 1; i--) {
    if (euclides(i, n) == 1) {
      resp = i;
      break;
    }
  }

  cout << resp << endl;

  return 0;
}
