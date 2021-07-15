#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0;i < n;i++)


typedef pair<ll, ll> Pair;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    x = abs(x);

    for (int i = 0;i < x / d;i++, k--) {
        x -= d;
    }

    if (k == 0) cout << x << endl;
    else {
        if (k % 2 == 0) cout << x << endl;
        else cout << abs(x - d) << endl;
    }
}
