#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define MOD (998244353)

ll n, m, k;
vector< vector<bool> > vec(5001, vector<bool>(5001, true));

ll solve(ll city, ll cnt) {
    if (cnt == k) {
        if (city == 1) return 1;
        else return 0;
    }

    ll rec = 0;
    for (ll i = 1;i <= n;i++) {
        if (i != city && vec[city][i]) rec = (rec + solve(i, cnt + 1)) % MOD;
    }

    return rec % MOD;
}

int main() {
    ll u, v;

    cin >> n >> m >> k;
    rep(i, m) {
        cin >> u >> v;
        vec[u][v] = false;
        vec[v][u] = false;
    }

    cout << solve(1, 0) % MOD << endl;    

    return 0;
}