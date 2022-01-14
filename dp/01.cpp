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

	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	vector<ll> dp(n, __LONG_LONG_MAX__);
	dp[0] = 0;

	rep(i, n) {
		if (i + 1 < n) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
		if (i + 2 < n) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
	}

	cout << dp[n - 1] << endl;

	return 0;
}