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
	ll n;
	cin >> n;

	vector<ll> t(n + 1);
	ll sum = 0;
	for (ll i = 1;i <= n;i++) {
		cin >> t[i];
		sum += t[i];
	}

	vector<vector<bool>> a(n + 1, vector<bool>(sum + 1, false));
	a[0][0] = true;
	for (ll i = 1;i <= n;i++) {
		for (ll j = 1;j <= sum;j++) {
			a[i][j] = a[i - 1][j];
			if (j - t[i] >= 0) a[i][j] = a[i][j] || a[i - 1][j - t[i]];
		}
	}

	ll ans = __LONG_LONG_MAX__;
	rep(i, sum + 1) {
		if (a[n - 1][i]) ans = min(ans, max(i, sum - i));
	}

	cout << ans << endl;

	return 0;
}