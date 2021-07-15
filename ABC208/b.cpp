#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0;i < n;i++)

int main() {
    vector<ll> v;

    rep(i, 10) {
        if (i == 0) v.push_back(1);
        else v.push_back(v[i - 1] * (i + 1));
    }

//    rep(i, 10) cout << v[i] << endl;

    ll p;
    ll ans = 0;
    cin >> p;

    for (int i = 9;i >= 0;i--) {
        ans += (p / v[i]);
        p %= v[i];
    }

    cout << ans << endl;

    return 0;
}
