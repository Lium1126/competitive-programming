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
	ll n, m, d;
	cin >> n >> m >> d;

	vector<ll> a(n);
	ll in;
	set<ll> b;
	rep(i, n) cin >> a[i];
	rep(i, m) {
		cin >> in;
		b.insert(in);
	}

	ll ans = -1;
	for (ll A : a) {
		auto lb = b.upper_bound(A + d);
		if (lb != b.begin()) lb--;
//		cout << A << ' ' << *lb << endl;
		if (abs(A - *lb) <= d) ans = max(ans, A + (*lb));
	}
	cout << ans << endl;

	return 0;
}