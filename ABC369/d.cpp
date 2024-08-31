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
	ll n;
	cin >> n;

	vector<ll> a(n + 1);
	irep(i, n) cin >> a[i];

	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
	irep(i, n) {
		if (i == 1) dp[i][0] = dp[i - 1][0];
		else dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + a[i] * 2);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
	}

	cout << max(dp[n][0], dp[n][1]) << endl;;

	return 0;
}