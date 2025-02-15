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
	string s;
	cin >> n >> s;

	ll cnt_one = 0;
	rep(i, n) if (s[i] == '1') cnt_one++;

	vector<P> zeros(n + 1);
	ll cnt = 0;
	irep(i, n) {
		char c = s[i - 1];
		if (c == '1') {
			cnt++;
			zeros[i] = P(0, 0);
		} else {
			zeros[i].first = cnt;
			zeros[i].second = cnt_one - cnt;
		}
	}

	vector<ll> left(n + 1, 0), right(n + 1, 0);
	irep(i, n) left[i] = left[i - 1] + zeros[i].first, right[i] = right[i - 1] + zeros[i].second;

	ll ans = __LONG_LONG_MAX__;
	irep(i, n) {
		if (s[i - 1] == '1') {
			ans = min(ans, (left[i - 1] - left[0]) + (right[n] - right[i]));
		}
	}

	cout << ans << endl;

	return 0;
}