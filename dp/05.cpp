#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

int main() {
	ll n, W, ans = 0;
	cin >> n >> W;

	vector<ll> w(n + 1), v(n + 1);
	rep(i, n) cin >> w[i] >> v[i];

	vector<vector<ll> > dp(n + 1, vector<ll>(n * 1000 + 1, W + 1));
	dp[0][0] = 0;

	for (ll i = 1;i <= n;i++) {
		for (ll j = 0;j <= 1000 * n;j++) {
			if (j == 0) dp[i][j] = 0;
			else if (0 <= j - v[i]) dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	for (ll i = 1000 * n;i >= 0;i--) {
		if (dp.back()[i] <= W) {
			cout << i << endl;
			return 0;
		}
	}

	cout << ans << endl;

	return 0;
}