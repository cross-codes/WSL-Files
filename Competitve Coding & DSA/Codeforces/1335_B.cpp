#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  int n, a, b;
  char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                  'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  while (t--) {
    cin >> n;
    cin >> a;
    cin >> b;
    string chose = "";
    for (int i = 0; i < b; i++) {
      chose += arr[i];
    }
    string orig = chose;
    int y = n % b;
    int x = n / b;
    if (n % b == 0) {
      while (--x) {
        chose += orig;
      }
    } else {
      while (--x) {
        chose += orig;
      }
      for (int i = 0; i < y; i++) {
        chose += orig[i];
      }
    }
    // cout << x << endl;

    cout << chose << endl;
  }
}
