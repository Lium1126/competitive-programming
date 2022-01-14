#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

typedef pair<ll, ll> P;

ll n, m;
vector<vector<P>> g(100005, vector<P>(0));
vector<ll> costs(100005, __LONG_LONG_MAX__);
vector<bool> visited(100005, false);

void dijkstra(ll start) {
	priority_queue<P, vector<P>, greater<P>> que;

	que.push(make_pair(0, start));
	costs[start] = 0;
	
	while(!que.empty()) {
		P now = que.top(); que.pop();
		ll pos = now.second;
		if (visited[pos]) continue;
		visited[pos] = true;

		for (auto next : g[pos]) {
			ll to = next.first, cost = costs[pos] + next.second;
			if (pos == 0) cost = next.second;
			if (costs[to] > cost) {
				costs[to] = cost;
				que.push(make_pair(cost, to));
			}
		}
	}
}

int main() {
	cin >> n >> m;

	ll a, b, c;
	rep(i, m) {
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	ll start = 1LL;
	dijkstra(start);

	cout << (costs[n] == __LONG_LONG_MAX__ ? -1 : costs[n]) << endl;

	return 0;
}