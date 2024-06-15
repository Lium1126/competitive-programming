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

ll solve(ll len, ll now, vector<ll> c) {
	if (len == now) return 1;

	ll rec = 0;
	rep(i, 26) {
		if (c[i] > 0) {
			vector<ll> t(c.size());
			copy(c.begin(), c.end(), t.begin());
			t[i]--;
			rec += solve(len, now + 1, t);
		}
	}

	return rec;
}

int main() {
	ll k;
	cin >> k;
	vector<ll> c(26);
	rep(i, 26) cin >> c[i];

	ll ans = 0;
	irep(i, k) {
		ans += solve(i, 0, c);
	}

	cout << ans << endl;

	return 0;
}