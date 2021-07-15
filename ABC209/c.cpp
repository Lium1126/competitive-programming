#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define MOD (1000000007)

int main() {
    ll n, in;
    ll ans = 1;
    vector<ll> v;

    cin >> n;
    rep(i, n) {
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin(), v.end());

    rep(i, n) ans = (ans * max((ll)0, v[i] - i)) % MOD;
    cout << ans << endl;

    return 0;
}
