#include <algorithm>
#include <iostream>
#define MAXN 212345
#define MAXH 2123456789
#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

long long h;
int n;
pair<int, int> asc[MAXN];

int main() {
  cin >> n >> h;

  for (int i = 1; i <= n; i++) {
    cin >> asc[i].F >> asc[i].S;
  }
  asc[0] = pii(0, 0);

  int begin = 0;
  int end = begin + h;
  int nextInterval = 1;
  int resp = 0;

  for (int i = 1; i <= n; i++) {
    begin = asc[i].F;
    end += begin - asc[i - 1].S;
    while (end > asc[nextInterval].first && nextInterval <= n) {
      end += asc[nextInterval].S - asc[nextInterval].F;
      nextInterval++;
    }
    resp = max(resp, end - begin);
  }

  cout << resp;

  return 0;
}
