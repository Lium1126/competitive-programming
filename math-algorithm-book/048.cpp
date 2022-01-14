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

typedef pair<ll, ll> P;

vector<vector<P> > g(100005, vector<P>(0));
vector<ll> dist(100005, __LONG_LONG_MAX__);
vector<bool> used(100005, false);

void dijkstra() {
	priority_queue<P, vector<P>, greater<P> > que;
	que.push(make_pair(0, 0));

	while (!que.empty()) {
		P focus = que.top(); que.pop();
		ll pos = focus.second;
		if (used[pos]) continue;

		used[pos] = true;
		for (P n : g[pos]) {
			ll to = n.first, cost = dist[pos] + n.second;
			if (pos == 0) cost = n.second;
			if (cost < dist[to]) {
				dist[to] = cost;
				que.push(make_pair(dist[to], to));
			}
		}
	}
	
}

int main() {
	ll k;
	cin >> k;

	rep(i, k) rep(j, 10) if (i != 0 || j != 0) g[i].push_back(make_pair((10 * i + j) % k, j));

	dijkstra();
	cout << dist[0] << endl;

	return 0;
}