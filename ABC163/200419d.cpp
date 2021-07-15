#include<bits/stdc++.h>
using ll = long long;
using namespace std;

#define MOD (1000000007)

ll n;
ll sum[200005] = {};

ll solve(ll m) {
    if(m == n + 1) return 1;
    ll max, min;
    min = sum[m - 1];
    max = sum[n] - sum[n - m];
    return (max - (min - 1)) % MOD;
}

int main() {
    ll k;
    ll ans = 0;
    cin >> n >> k;

    if (n < k) {
        cout << "1" << endl;
    } else {
        for(ll i = 1;i <= n;i++) {
            sum[i] = sum[i - 1] + i;
        }
        for(ll i = k;i <= n + 1;i++) {
            ans = (ans + solve(i)) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}
