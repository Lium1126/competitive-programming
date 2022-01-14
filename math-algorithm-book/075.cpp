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

vector<mint> fact(200009);
ll n;

mint ncr(ll n, ll r) {
	return fact[n] / (fact[r] * fact[n - r]);
}

int main() {
	fact[0] = 1;
	for (ll i = 1;i <= 200000;i++) fact[i] = fact[i - 1] * i;

	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	mint ans = 0;
	rep(i, n) ans += a[i] * ncr(n - 1, i);

	cout << ans.val() << endl;

	return 0;
}