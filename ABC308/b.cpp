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
	ll ans = 0;
	ll n, m;
	cin >> n >> m;
	vector<string> c(n), d(m);
	vector<ll> p(m + 1);

	rep(i, n) cin >> c[i];
	rep(i, m) cin >> d[i];
	rep(i, m + 1) cin >> p[i];

	map<string, ll> mp;
	rep(i, m) {
		mp[d[i]] = p[i + 1];
	}

	rep(i, n) {
		ans += (mp[c[i]] == 0 ? p[0] : mp[c[i]]);
	}
	cout << ans << endl;

	return 0;
}