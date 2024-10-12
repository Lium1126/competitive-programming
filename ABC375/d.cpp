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

ll solve(vector<ll> s) {
	ll ret = 0;

	ll minimum = s[0];
	ll maximum = s[s.size() - 1];
	// cout << minimum << ' ' << maximum << endl;

	for (ll i = minimum + 1;i <= maximum - 1;i++) {
		auto itr = lower_bound(s.begin(), s.end(), i);
		ll idx = itr - s.begin();
		ll left, right;
		if (*itr == i) {
			left = idx;
			right = s.size() - 1 - idx;
		} else {
			left = idx;
			right = s.size() - idx;
		}
		// cout << i << ": " << left << ' ' << right << endl;

		ret += left * right;
	}

	return ret;
}

int main() {
	string s;
	cin >> s;

	vector<vector<ll>> v(26);
	ll ans = 0;
	rep(i, s.length()) v[s[i] - 'A'].push_back(i);

	rep(i, 26) {
		if (v[i].size() >= 2) ans += solve(v[i]);
	}

	cout << ans << endl;

	return 0;
}