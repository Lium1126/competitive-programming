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
	ll n, W;
	cin >> n >> W;

	vector<ll> w(n + 1), v(n + 1);
	rep(i, n) cin >> w[i] >> v[i];

	vector<vector<ll> > dp(n + 1, vector<ll>(W + 1, 0));

	rep(i, n) {
		rep(j, W) {
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][W] << endl;

	return 0;
}