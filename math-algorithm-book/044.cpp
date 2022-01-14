#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, m;
	vector<ll> dist(100009, -1);
	vector<vector<ll> > g(100009, vector<ll>(0));

	cin >> n >> m;

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<ll> que;
	que.push(1); dist[1] = 0;

	while (!que.empty()) {
		ll pos = que.front(); que.pop();
		for (ll next : g[pos]) if (dist[next] == -1) que.push(next), dist[next] = dist[pos] + 1;
	}
	
	for (ll i = 1;i <= n;i++) cout << dist[i] << endl;

	return 0;
}