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

	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	
	vector<ll> tmp(n + 5, 0), l(n);
	ll s = 0;
	rep(i, n) {
		if (tmp[a[i]] == 0) s++, tmp[a[i]] = 1;
		l[i] = s;
	}

	vector<ll> tmp2(n + 5, 0), r(n);
	s = 0;
	reverse(a.begin(), a.end());
	rep(i, n) {
		if (tmp2[a[i]] == 0) s++, tmp2[a[i]] = 1;
		r[i] = s;
	}
	reverse(r.begin(), r.end());

	ll ans = 0;
	rep(i, n - 1) {
		ans = max(ans, l[i] + r[i + 1]);
	}
	cout << ans << endl;

	return 0;
}