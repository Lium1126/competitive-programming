#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    ll ans = 0;
    for (ll i = 1;i <= n;i++) {
        ll y = n / i;
        ans += y * (y + 1) * i / 2;
    }

    cout << ans << endl;

    return 0;
}
