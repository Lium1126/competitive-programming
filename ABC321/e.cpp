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

ll n, x, k;

ll two_pow(ll x) {
	ll rec = 1;
	rep(i, x) rec <<= 1;
	return rec;
}

int main() {
	ll t;
	cin >> t;

	while (t--) {
		cin >> n >> x >> k;

		if (k == 0) {
			cout << 1 << endl;
			continue;
		}

		ll tmp = 1, cnt = 0;
		while (tmp <= x) {
			cnt++;
			tmp <<= 1;
		}
		ll level = cnt - 1;

		// cout << "------" << endl;
		// cout << x << ": level " << level << endl;
		// cout << pow(2.0, level) << " <= " << x << " < " << pow(2.0, level + 1) << endl;

		ll ans = 0;
		// 子要素を探索(左)
		ll target_level = level + k;
		ll sh = (two_pow(target_level) + (two_pow(target_level + 1) - 1)) / 2;
		// cout << two_pow(target_level) << " ~ " << two_pow(target_level + 1) << ": " << sh << endl;
		if (two_pow(target_level) <= n) {
			ans += min(sh, n) - two_pow(target_level) + 1;
		}

		// 親から探索(右)
		target_level = level - k;
		if (target_level >= 0) ans++;
		else {
			target_level = abs(target_level);
			// cout << "k = " << k << ", target = " << target_level << endl;
			ll sh = (two_pow(target_level) + (two_pow(target_level + 1) - 1)) / 2 + 1;
			// cout << sh << " ~ " << two_pow(target_level + 1) - 1 << endl;
			if (sh <= n) ans += min(n, two_pow(target_level + 1) - 1) - sh + 1;
		}

		cout << ans << endl;
	}

	return 0;
}