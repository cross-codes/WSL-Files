#include <bits/stdc++.h>

using namespace std;

int main() {
  int arr[] = {1, 3, 3, 3, 3, 4, 6, 7};
  int n = 8;
  auto a = lower_bound(arr, arr + n, 3);
  auto b = upper_bound(arr, arr + n, 3);
  auto c = lower_bound(arr, arr + n, 2);
  auto d = upper_bound(arr, arr + n, 2);
  cout << a - arr << "\n";
  cout << b - arr << "\n";
  cout << c - arr << "\n";
  cout << d - arr << "\n";

  return 0;
}
