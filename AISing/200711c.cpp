#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

ll f(ll n) {
    ll cnt = 0;

    for(ll i = 1;i <= (ll)sqrt(n);i++) {
        for(ll j = 1;j <= (ll)sqrt(n);j++) {
            ll b = (i + j);
            ll c = ((i * i) + (j * j) + (i * j) - n);
            ll d = b * b - (4 * c);
//            cout << n << ":(" << i << "," << j << "):" << "d=" << d << endl;
            if (-b + (ll)sqrt(d) > 0 && (-b + (ll)sqrt(d)) % 2 == 0) cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    for(ll i = 1;i <= n;i++) cout << f(i) << endl;

    return(0);
}
