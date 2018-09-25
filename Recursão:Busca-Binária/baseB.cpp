// IntToBaseB Solution (EP16 - MAC110)

#include <bits/stdc++.h>
using namespace std;

char symbols[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b',
                  'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                  'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};

string baseB(int n, int b) {
  // base cases
  if (n == 0) return "";
  if (n == 1) return "1";

  return (baseB(n / b, b) + symbols[n % b]);
}

int ini, base;

int main() {
  scanf("%d %d", &base, &ini);

  cout << baseB(ini, base) << endl;
  return 0;
}
