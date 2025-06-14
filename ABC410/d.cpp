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

	vector<vector<P>> g(n, vector<P>());
	ll s, t, w;
	rep(i, m) {
		cin >> s >> t >> w;
		s--; t--;
		g[s].push_back(P(t, w));
	}

	vector<ll> b;
	set<P> visited;
	queue<P> que;
	que.push(P{0, 0});
	while(!que.empty()) {
		P now = que.front(); que.pop();
		if (visited.find(now) != visited.end()) continue;
		visited.insert(now);
		for (P next : g[now.first]) {
			ll nn = next.first;
			ll nw = next.second;
			ll nxor = now.second ^ nw;
			P state = P{nn, nxor};
			if (visited.find(state) != visited.end()) {
				ll cycle = 0;
				for (P p : visited) {
					if (p.first == nn && p.second == nxor) {
						cycle = now.second ^ nw ^ p.second;
						break;
					}
				}
				b.push_back(cycle);
				continue;
			}
			que.push(state);
		}
	}

	ll ans = __LONG_LONG_MAX__;
	for (P p : visited) {
		if (p.first == n - 1) {
			ll tmp = p.second;
			for (ll b : b) tmp = min(tmp, tmp ^ b);
			ans = min(ans, tmp);
		}
	}
	cout << (ans == __LONG_LONG_MAX__ ? -1 : ans) << endl;

	return 0;
}