#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define MOD (998244353)

int main() {
    ll p;
    cin >> p;
    set<ll> s;
    ll ans = 2;

    for (ll x = 2;x < p;x++) {
        s.clear();
        ll hoge = 1;
        do {
            s.insert(hoge % p);
            hoge *= x;
        } while(hoge < p);
        ans = (ans + s.size()) % MOD;
    }

    cout << ans << endl;

    return 0;
}