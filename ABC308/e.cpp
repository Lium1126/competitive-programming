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

ll mex(ll m, ll e, ll x) {
	ll ret = 15;
	ret &= ~(1 << m);
	ret &= ~(1 << e);
	ret &= ~(1 << x);
	if ((ret & 1) != 0) return 0;
	if ((ret & 2) != 0) return 1;
	if ((ret & 4) != 0) return 2;
	return 3;
}

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	string s;
	cin >> s;

	vector<vector<ll>> m(3), x(3);
	rep(i, n) {
		if (s[i] == 'M') m[a[i]].push_back(i);
		if (s[i] == 'X') x[a[i]].push_back(i);
	}
/*
	rep(i, 3) {
		cout <<"m "<< i << ": ";
		for (ll out : m[i]) cout << out << ' ';
		cout << endl;
	}
	rep(i, 3) {
		cout <<"x "<< i << ": ";
		for (ll out : x[i]) cout << out << ' ';
		cout << endl;
	}
*/

	ll ans = 0;
	rep(i, n) {
		if (s[i] == 'E') {
		rep(ma, 3) {
		rep(xa, 3) {
			ll M = (m[ma].size() == 0 ? 0 : lower_bound(m[ma].begin(), m[ma].end(), i) - m[ma].begin());
			ll X = (x[xa].size() == 0 ? 0 : x[xa].end() - lower_bound(x[xa].begin(), x[xa].end(), i));
			ans += mex(ma, a[i], xa) * (M * X);
		}
		}
		}
	}

	cout << ans << endl;

	return 0;
}