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

ll to_bin(string s) {
	ll rec = 0;
	rep(i, s.length()) {
		rec <<= 1;
		if (s[i] == 'o') rec++;
	}
	return rec;
}

int main() {
	ll n, m;
	cin >> n >> m;

	string s;
	vector<ll> vec(n);
	rep(i, n) {
		cin >> s;
		vec[i] = to_bin(s);
		// cout << vec[i] << endl;
	}

	ll ans = __LONG_LONG_MAX__;
	for (ll i = 0;i <= (1 << n) - 1;i++) {
		ll tmp = 0, cnt = 0;

		rep(j, n) {
			if ((1 << j) & i) {
				cnt++;
				rep(k, m) {
					tmp |= (vec[j] & (1 << k));
				}
			}
		}

		if (tmp == (1 << m) - 1) ans = min(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}