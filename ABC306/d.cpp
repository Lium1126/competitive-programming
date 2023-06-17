#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll n, x, y;
	cin >> n;
	vector<vector<ll>> dp(2, vector<ll>(n + 1, 0));
//	vector<vector<ll>> dp2(2, vector<ll>(n + 1, 0));

	irep(i, n) {
		cin >> x >> y;

		if (x == 0) {
			// 解毒剤
			// 0->0, 1->0, 1->1
			dp[0][i] = max(max(dp[0][i - 1] + y, dp[1][i - 1] + y), dp[0][i - 1]);
			dp[1][i] = dp[1][i - 1];
//			dp2[0][i] = min(dp2[0][i - 1] + y, dp2[1][i - 1] + y);
//			dp2[1][i] = dp2[1][i - 1];
		} else {
			// 1->1, 0->1, 0->0
			dp[1][i] = max(dp[0][i - 1] + y, dp[1][i - 1]);
			dp[0][i] = dp[0][i - 1];
//			dp2[0][i] = min(dp2[0][i - 1] + y, dp2[1][i - 1] + y);
//			dp2[1][i] = dp2[1][i - 1];
		}
	}
	cout << max(dp[0][n], dp[1][n]) << endl;
//	cout << dp[0][n] << ' ' << dp[1][n] << endl;
//	cout << dp2[0][n] << ' ' << dp[1][n] << endl;
/*
	rep(i, 2) {
		for (ll out : dp[i]) {
			cout << out << ' ';
		}
		cout << endl;
	}
*/
	return 0;
}