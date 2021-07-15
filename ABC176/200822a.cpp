#include <bits/stdc++.h>
#define rep (i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int main () {
    int n, x, t;
    cin >> n >> x >> t;
    if (n % x == 0) {
        cout << (n / x) * t << endl;
    } else {
        cout << (n / x) * t + t << endl;
    }
    return(0);
}
