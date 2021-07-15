#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> A, B;
    for (int i = 0;i < n;i++) {
        ll input;
        cin >> input;
        A.push_back(input);
    }
    for (int i = 0;i < m;i++) {
        ll input;
        cin >> input;
        B.push_back(input);
    }

    vector<ll> a, b;
    a.push_back(0); b.push_back(0);

    for (int i = 0;i < n;i++) {
        a.push_back(a[i] + A[i]);
    }
    for (int i = 0;i < m;i++) {
        b.push_back(b[i] + B[i]);
    }

    ll j = m;
    ll ans = 0;
    for (int i = 0;i <= n;i++) {
        if (a[i] > k) break;
        while (b[j] > k - a[i]) {
            j--;
        }
        ans = max(ans, i + j);
    }

    cout << ans << endl;

    return 0;
}
