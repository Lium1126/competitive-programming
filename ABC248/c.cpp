#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint998244353;

ll n, m, k;

int main() {
	cin >> n >> m >> k;
	
	vector<vector<mint>> dp(55, vector<mint>(2505, 0));
	dp[0][0] = 1;
	rep(i, n) {
		rep(j, k) {
			for (ll cnt = 1;cnt <= m;cnt++) {
				if (j + cnt <= k) dp[i + 1][j + cnt] += dp[i][j];
			}
		}
	}
	mint ans = 0;
	for (ll i = 1;i <= k;i++) ans += dp[n][i];
	cout << ans.val() << endl;

	return 0;
}