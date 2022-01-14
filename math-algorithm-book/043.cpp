#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll n, m;
vector<vector<ll> > g(100009, vector<ll>(0));
vector<bool> visited(100009, false);

void dfs(ll pos) {
	visited[pos] = true;
	for (ll next : g[pos]) if (!visited[next]) dfs(next);
}

int main() {
	ll a, b;

	cin >> n >> m;
	rep(i, m) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(1);

	bool ans = true;
	for (ll i = 1;i <= n;i++) if (!visited[i]) ans = false;

	cout << (ans ? "The graph is connected." : "The graph is not connected.") << endl;

	return 0;
}