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
	ll n, k;
	cin >> n >> k;

	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	vector<ll> dp(n, __LONG_LONG_MAX__);
	dp[0] = 0;

	rep(i, n) {
		for (ll j = 1;j <= k;j++)
			if (i + j < n) dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
	}

	cout << dp[n - 1] << endl;

	return 0;
}