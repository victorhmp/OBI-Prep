// Binary Search recursive implementation
// O(x log n)

#include <cstdio>
#include <iostream>

#define MAXN 110000

using namespace std;

int binary(int arr[], int low, int hi, int x) {
  if (low < hi) {
    int mid = low + (hi - low) / 2;

    if (arr[mid] == x) return mid;
    if (arr[mid] < x) return binary(arr, mid + 1, hi, x);
    if (arr[mid] > x) return binary(arr, low, mid, x);
  }

  return -(low + 1);
}

int n, x;
int arr[MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];

  while (cin >> x) cout << binary(arr, 0, n, x) << endl;
}
