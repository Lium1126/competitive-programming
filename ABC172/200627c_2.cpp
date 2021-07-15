#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, k;
vector<ll> a;
vector<ll> b;

ll solve(int a_i, int b_i, int num, ll t) {
    //printf("%d %d %d %lld\n", a_i, b_i, num, t);
    if ((t + a[a_i] > k && t + b[b_i] > k) || (a_i == n && b_i == m)) {
        return num;
    }

    ll ret1 = 0;
    ll ret2 = 0;
    if (a_i < n && a[a_i] + t <= k){
        ret1 = solve(a_i + 1, b_i, num + 1, t + a[a_i]);
    }
    if (b_i < m && b[b_i] + t <= k) {
        ret2 = solve(a_i, b_i + 1, num + 1, t + b[b_i]);
    }

    return max(ret1, ret2);
}

int main() {
    cin >> n >> m >> k;
    for (ll i = 0;i < n;i++) {
        ll input;
        cin >> input;
        a.push_back(input);
    }
    for (ll i = 0;i < m;i++) {
        ll input;
        cin >> input;
        b.push_back(input);
    }

    cout << solve(0, 0, 0, 0) << endl;

    return 0;
}
