#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
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

ll longestArithmeticSubsequence(vector<ll>& nums) {
    ll n = nums.size();
    if (n < 2) return n;

    vector<unordered_map<ll, ll>> dp(n);
    ll maxLength = 2;

    for (ll i = 1; i < n; ++i) {
        for (ll j = 0; j < i; ++j) {
            ll d = nums[i] - nums[j];
            dp[i][d] = dp[j].count(d) ? dp[j][d] + 1 : 2;
            maxLength = max(maxLength, dp[i][d]);
        }
    }

    return maxLength;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];

	ll ans = 1;

	map<ll, vector<ll>> m;
	rep(i, n) {
		m[h[i]].push_back(i);
	}

	for (auto itr = m.begin();itr != m.end();itr++) {
        ans = max(ans, longestArithmeticSubsequence(itr->second));
    }

	cout << ans << endl;

	return 0;
}