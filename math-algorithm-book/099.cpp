#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll n;
vector<vector<ll>> g(100009, vector<ll>(0));
vector<bool> visited(100009, false);
vector<ll> cost(100009, 0);

void dfs(ll now) {
	visited[now] = true;
	cost[now] = 1;
	for (ll next : g[now]) {
		if (!visited[next]) {
			dfs(next);
			cost[now] += cost[next];
		}
	}
}

int main() {
	cin >> n;

	ll a, b;
	rep(i, n - 1) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	ll ans = 0;
	for (ll i = 2;i <= n;i++) {
		ans += cost[i] * (n - cost[i]);
	}

	cout << ans << endl;

	return 0;
}