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
	ll l, r;
	cin >> l >> r;

	vector<bool> isp(1000009, true);
	isp[0] = isp[1] = false;
	for (ll i = 2;i * i <= r;i++) {
		if (isp[i]) for (ll j = 2 * i;j * j <= r;j += i) isp[j] = false;
	}

	vector<bool> p(500009, true);
	if (l == 1) p[0] = false;

	for (ll i = 2;i * i <= r;i++) {
		if (isp[i]) {
			ll s = ((l + i - 1) / i ) * i;
			for (ll j = s;j <= r;j += i) if (j != i) p[j - l] = false;
		}
	}

	ll ans = 0;
	for (ll i = 0;i <= r - l;i++) if (p[i]) ans++;
	cout << ans << endl;

	return 0;
}