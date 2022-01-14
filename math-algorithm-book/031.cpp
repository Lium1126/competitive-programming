#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll unsigned long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll n;
vector<ll> a(500005), mem(500005, -1);

int main() {
	cin >> n;
	for (ll i = 1;i <= n;i++) cin >> a[i];

	vector<vector<ll> > dp(n + 1, vector<ll>(2, 0));
	dp[0][1] = a[1];
	dp[1][0] = a[1];
	dp[1][1] = a[2];

	for (ll i = 2;i < n;i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + a[i + 1];
	}

	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

	return 0;
}