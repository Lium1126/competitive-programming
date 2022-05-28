#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (998244353)

using namespace std;
using mint = atcoder::modint998244353;

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<mint>> dp(m + 1, vector<mint>(n + 1, 0));
	vector<mint> sum(m + 1, 0);
	for (ll i = 1;i <= m;i++) {
		dp[i][1] = 1;
		sum[i] = sum[i - 1] + 1;
	}

	for (ll i = 2;i <= n;i++) {
		for (ll j = 1;j <= m;j++) {
			ll l = max((ll)1, j - (k - 1));
			ll r = min(m, j + (k - 1));
			if (k == 0) dp[j][i] = sum[m];
			else dp[j][i] = sum[m] - (sum[r] - sum[l - 1]);
		}

		for (ll j = 1;j <= m;j++) sum[j] = sum[j - 1] + dp[j][i];
	}

	mint tmp = 0;
	for (ll i = 1;i <= m;i++) tmp += dp[i][n];

	cout << tmp.val() << endl;

/*
	for (ll i = 1;i <= m;i++) {
		for (ll j = 1;j <= n;j++) cout << dp[i][j].val() << ' ';
		cout << endl;
	}
*/

	return 0;
}