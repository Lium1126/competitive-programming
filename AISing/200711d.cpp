#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int f(int i) {
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int base = 0;
    rep (i, n) {
        base <<= 1;
        base |= (s[i] - '0');
    }

    int m  = (1 << (n - 1));
    rep (i, n) {
        int now = base ^ m;
        m >>= 1;

        int cnt = 1;
        int tmp = f(now);
        while (now % tmp != 0) {
            cnt++;
            now = now % tmp;
            tmp = f(now);
        }

        cout << cnt << endl;
    }

    return(0);
}
