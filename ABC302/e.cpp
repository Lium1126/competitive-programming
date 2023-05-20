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
	ll n, q;
	cin >> n >> q;

	vector<set<ll>> g(n + 1);

	set<ll> emp;
	ll ans = n;
	ll x, u, v;
	rep(i, q) {
		cin >> x;
		if (x == 1) {
			cin >> u >> v;
			if(g[u].size() == 0) ans--;
			g[u].insert(v);
			if(g[v].size() == 0) ans--;
			g[v].insert(u);
		}
		else {
			cin >> u;
			if (g[u].size() != 0) ans++;
			for (auto itr = g[u].begin();itr != g[u].end();itr++) {
				if (g[*itr].size() == 1) ans++;
				g[*itr].erase(u);
			}
			g[u] = emp;
		}
		cout << ans << endl;
	}

	return 0;
}