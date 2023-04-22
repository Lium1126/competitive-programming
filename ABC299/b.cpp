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
	ll n, t;
	cin >> n >> t;

	ll one;
	map<ll, vector<P>> m;
	vector<P> v(n);
	rep(i, n) {
		cin >> v[i].first;
		if (i == 0) one = v[i].first;
	}
	rep(i, n) cin >> v[i].second;

	rep(i, n) {
		m[v[i].first].push_back(P{v[i].second, i});
	}

	ll target = (m[t].size() != 0 ? t : v[0].first);
	ll maxmum = 0, ans = 0;
	for (P p: m[target]) {
		if (maxmum < p.first) {
			maxmum = p.first;
			ans = p.second;
		}
	}

	cout << ans+1 << endl;

	return 0;
}