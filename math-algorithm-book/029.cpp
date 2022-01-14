#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	for (ll i = 1;i <= n;i++) {
		if (i - 1 >= 0) dp[i] += dp[i - 1];
		if (i - 2 >= 0) dp[i] += dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}