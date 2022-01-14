#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<vector<ll> > a(n + 1, vector<ll>(3));
	for (ll i = 1;i <= n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

	vector<vector<ll> > dp(n + 1, vector<ll>(3, 0));
	for (ll i = 1;i <= n;i++) {
		rep(j, 3) {
			dp[i][j] = max(dp[i][j], dp[i - 1][(j + 1) % 3] + a[i][j]);
			dp[i][j] = max(dp[i][j], dp[i - 1][(j + 2) % 3] + a[i][j]);
		}
	}

	cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;

	return 0;
}