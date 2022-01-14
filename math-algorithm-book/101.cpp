#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint1000000007;

ll n;
vector<mint> fact(100009, 0);

mint ncr(ll n, ll r) {
	return fact[n] / (fact[r] * fact[n - r]);
}

int main() {
	fact[0] = 1;
	for (ll i = 1;i <= 100000;i++) fact[i] = fact[i - 1] * i;

	ll n;
	cin >> n;
	
	for (ll i = 1;i <= n;i++) {
		mint ans = 0;
		for (ll j = 1;j <= (n + i - 1) / i;j++)	ans += ncr(n - (i - 1) * (j - 1), j);

		cout << ans.val() << endl;
	}

	return 0;
}