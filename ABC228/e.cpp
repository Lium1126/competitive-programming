#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

#define MOD (998244353)

ll low_mypow(ll x, ll n) {
	ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = (x * ret) % (MOD - 1);
        x = (x * x) % (MOD - 1);
        n >>= 1;
    }
    return ret % (MOD - 1);
}

ll mypow(ll x, ll n) {
	ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = (x * ret) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

int main()
{
	ll n, k, m;

	cin >> n >> k >> m;

	cout << mypow(m, low_mypow(k, n)) % MOD << endl;

	return 0;
}