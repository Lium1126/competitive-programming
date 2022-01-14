#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, k, ans = 0;
	cin >> n >> k;

	vector<ll> a(k);
	rep(i, k) cin >> a[i];

	for (ll i = 1;i < (1LL << k);i++) {
		ll LCM = 1, cnt = 0;
		rep(j, k) if ((i & (1LL << j))) LCM = lcm(LCM, a[j]), cnt++;

		if (cnt & 1) ans += (n / LCM);
		else ans -= (n / LCM);
	}

	cout << ans << endl;

	return 0;
}