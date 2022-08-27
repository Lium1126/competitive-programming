#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, t, x, a;
	ll tl = 0;
	cin >> n;

	vector<vector<ll>> v(100005, vector<ll>(5, 0));

	rep(i, n) {
		cin >> t >> x >> a;
		v[t][x] += a;
		tl = max(tl, t);
	}

	ll d[3] = {-1, 0, 1};
	vector<vector<ll>> dp(100005, vector<ll>(5, 0));
	rep(i, tl + 1) {
		rep(j, min((ll)5, i + 1)) {
			dp[i][j] += v[i][j];
			rep(k, 3) {
				ll next = j + d[k];
				if (0 <= next && next < 5) dp[i + 1][next] = max(dp[i + 1][next], dp[i][j]);
			}
		}
	}

	ll ans = 0;
	rep(i, 5) ans = max(ans, dp[tl][i]);
	cout << ans << endl;

	return 0;
}