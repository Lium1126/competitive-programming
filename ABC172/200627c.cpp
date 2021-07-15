#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF (1 << 63)

ll solve(ll n, ll m, ll k, queue<ll> a, queue<ll> b, ll total, ll ans) {
    if (total + a.front() > k && total > b.front() > k) {
        return ans;
    }
    ll ret1 = INF;
    ll ret2 = INF;
    ll t1 = a.front();
    ll t2 = b.front();
    if (total + t1 <= k) {
        queue<ll> tmp = a;
        tmp.pop();
        ret1 = solve(n, m, k, tmp, b, total + t1, n + 1);
    }
    if (total + b <= k) {
        queue<ll> tmp = b;
        tmp.pop();
        ret2 = solve(n, m, k, a, tmp, total + t2, n + 1);
    }
    return min(ret1, ret2);
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    queue<ll> a;
    queue<ll> b;
    for (ll i = 0;i < n;i++) {
        ll input;
        cin >> input;
        a.push(input);
    }
    for (ll i = 0;i < m;i++) {
        ll input;
        cin >> input;
        b.push(input);
    }

    cout << solve(n, m, k, a, b, 0, 0) << endl;

    return 0;
}
