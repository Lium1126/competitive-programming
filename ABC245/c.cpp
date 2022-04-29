#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> a(2, vector<ll>(n));
	rep(i, n) cin >> a[0][i];
	rep(i, n) cin >> a[1][i];
	vector<vector<bool>> dp(2, vector<bool>(n, false));
	dp[0][0] = dp[1][0] = true;
	for (ll i = 1;i < n;i++) {
		rep(j, 2) {
			if (dp[0][i - 1] && abs(a[0][i - 1] - a[j][i]) <= k || dp[1][i - 1] && abs(a[1][i - 1] - a[j][i]) <= k) dp[j][i] = true;
		}
	}
	cout << (dp[0][n - 1] || dp[1][n - 1] ? "Yes" : "No") << endl;
	return 0;
}