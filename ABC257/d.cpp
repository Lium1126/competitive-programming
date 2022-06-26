#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>
#include <queue>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

ll n;
vector<P> d(205);
vector<ll> p(205);

ll dist(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ll x, y, Power;
	cin >> n;

	for (ll i = 1;i <= n;i++) {
		cin >> x >> y >> Power;
		d[i] = make_pair(x, y);
		p[i] = Power;
	}

	vector<vector<ll>> g(205, vector<ll>(205, __LONG_LONG_MAX__));
	for (ll i = 1;i <= n;i++) {
		for (ll j = 1;j <= n;j++) {
			g[i][j] = (dist(d[i], d[j]) + p[i] - 1) / p[i];
		}
	}

	for (ll i = 1;i <= n;i++) {
		for (ll j = 1;j <= n;j++) {
			for (ll k = 1;k <= n;k++) {
				g[j][k] = min(g[j][k], max(g[j][i], g[i][k]));
			}
		}
	}

	ll ans = __LONG_LONG_MAX__;
	for (ll i = 1;i <= n;i++) {
		ll tmp = 0;
		for (ll j = 1;j <= n;j++) tmp = max(tmp, g[i][j]);
		ans = min(ans, tmp);
	}

	cout << ans << endl;

	return 0;
}