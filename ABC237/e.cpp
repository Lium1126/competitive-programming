#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

ll n, m;
vector<vector<P>> g(200005);
vector<ll> h(200005);

ll dfs(ll now, ll cost, set<ll> visited) {
	ll ret = cost;

	for (P next : g[now]) {
		if (visited.find(next.first) == visited.end()) {
			set<ll> tmp = visited;
			tmp.insert(next.first);
			ret = max(ret, dfs(next.first, cost + next.second, tmp));
		}
	}

	return ret;
}

int main() {
	cin >> n >> m;
	for (ll i = 1;i <= n;i++) cin >> h[i];
	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		if (h[a] < h[b]) swap(a, b);
		if (h[a] != h[b]) {
			g[a].push_back(P{b, h[a] - h[b]});
			g[b].push_back(P{a, 2 * (h[b] - h[a])});
		} else {
			g[a].push_back(P{a, 0});
			g[b].push_back(P{b, 0});
		}
	}

/*
	for (ll i = 1;i <= n;i++) {
		cout << i << ": ";
		rep(j, g[i].size()) cout << "(" << g[i][j].first << ", " << g[i][j].second << "), ";
		cout << endl;
	}
*/

	set<ll> empty;
	cout << dfs(1, 0,  empty) << endl;

	return 0;
}