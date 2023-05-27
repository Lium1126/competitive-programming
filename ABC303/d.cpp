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

#define CAPS_OFF (0)
#define CAPS_ON (1)

int main() {
	ll x, y, z;
	cin >> x >> y >> z;
	string s;
	cin >> s;
	ll n = s.length();

	s = '.' + s;
	vector<vector<ll>> dp(n + 1, vector<ll>(2, __LONG_LONG_MAX__));
	dp[0][CAPS_ON] = z; dp[0][CAPS_OFF] = 0;

	irep(i, n) {
		if (s[i] == 'A') {
			dp[i][CAPS_OFF] = min(dp[i - 1][CAPS_OFF] + y, dp[i - 1][CAPS_ON] + z + x);
			dp[i][CAPS_ON] = min(dp[i - 1][CAPS_OFF] + z + y, dp[i - 1][CAPS_ON] + x);
		} else { // 'a'
			dp[i][CAPS_OFF] = min(dp[i - 1][CAPS_OFF] + x, dp[i - 1][CAPS_ON] + z + y);
			dp[i][CAPS_ON] = min(dp[i - 1][CAPS_OFF] + z + x, dp[i - 1][CAPS_ON] + y);
		}
	}

	cout << min(dp[n][CAPS_OFF], dp[n][CAPS_ON]) << endl;

	return 0;
}