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
	map<ll, vector<ll>> g;
	ll u, v;
	rep(i, n - 1) {
		cin >> u >> v;
		u--, v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	ll ans = n;
	rep(i, n) {
		ll tmp = __LONG_LONG_MAX__;
		ll cnt = 0;
		for (ll node : g[i]) {
			if (g[node].size() - 1 == 0) cnt++;
			else tmp = min(tmp, (ll)(g[node].size() - 1));
		}
		if (cnt == g[i].size()) continue;

		ll snowTreeNodes = 1 + g[i].size() + (g[i].size() * tmp);
		ans = min(ans, n - snowTreeNodes);
	}

	cout << ans << endl;

	return 0;
}