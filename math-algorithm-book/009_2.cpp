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
	ll n, s;
	cin >> n >> s;

	vector<ll> a(n + 1);
	rep(i, n) cin >> a[i];

	vector<vector<ll> > dp(s + 1, vector<ll>(n + 1, 0));
	dp[0][0] = 1;

	rep(i, n) {
		for (ll j = 0;j <= s;j++) {
			dp[j][i] = max(dp[j][i - 1], dp[j][i]);
			if (j - a[i] >= 0) dp[j][i] = max(dp[j - a[i]][i - 1], dp[j][i]);
		}
	}

	cout << (dp[s][n] == 1 ? "Yes" : "No") << endl;

	return 0;
}