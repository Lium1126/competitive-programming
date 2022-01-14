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
	ll n, W;
	cin >> n >> W;

	vector<ll> v(n + 1), w(n + 1);
	for (ll i = 1;i <= n;i++) cin >> w[i] >> v[i];

	vector<vector<ll> > dp(n + 1, vector<ll>(100001, 0));
	for (ll i = 1;i <= n;i++) {
		rep(j, W + 1) {
			if (j < w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	ll ans = 0;
	rep(i, W + 1) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}