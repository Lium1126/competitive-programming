#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a;
    a.push_back(0);  // ダミーデータ
    ll in;
    rep(i, n) {
        cin >> in;
        a.push_back(in);
    }

	sort(a.begin(), a.end());

    ll ans = 0;
    for (int k = 1;k <= n - 1;k++) {
        ans += a[n - k / 2];
    }

    cout << ans << endl;

    return(0);
}
