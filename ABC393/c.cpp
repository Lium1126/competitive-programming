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
	ll n, m;
	cin >> n >> m;

	vector<set<ll>> g(200005);
	ll u, v;
	ll ans = 0;
	rep(i, m) {
		cin >> u >> v;

		if (u == v) ans++;
		else if (g[u].find(v) != g[u].end()) ans++;

		g[u].insert(v);
		g[v].insert(u);
	}

	cout << ans << endl;

	return 0;
}