#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <functional>
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
typedef pair<P, bool> PP;

int main() {
	ll n, m, x;
	cin >> n >> m >> x;

	vector<vector<set<ll>>> g(2, vector<set<ll>>(n + 1));
	ll from, to;
	rep(i, m) {
		cin >> from >> to;
		g[0][from].insert(to);
		g[1][to].insert(from);
	}

	vector<vector<ll>> distance(2, vector<ll>(n + 1, __LONG_LONG_MAX__));
	distance[0][1] = 0;
	priority_queue<PP, vector<PP>, greater<PP>> que;
	que.emplace(PP(P(0LL, 1LL), false));
	while (!que.empty()) {
		PP now = que.top(); que.pop();
		ll cost = now.first.first;
		ll pos = now.first.second;
		bool reversed = now.second;
		
		if (distance[(reversed ? 1 : 0)][pos] < cost) continue;

		for (ll next: g[(reversed ? 1 : 0)][pos]) {
			ll d = distance[(reversed ? 1 : 0)][pos] + 1;
			if (d < distance[(reversed ? 1 : 0)][next])	{
				distance[(reversed ? 1 : 0)][next] = d;
				que.emplace(PP(P(d, next), reversed));
			}
		}

		ll d = distance[(reversed ? 1 : 0)][pos] + x;
		if (d < distance[(!reversed ? 1 : 0)][pos]) {
			distance[(!reversed ? 1 : 0)][pos] = d;
			que.emplace(PP(P(d, pos), !reversed));
		}
	}

	cout << min(distance[0][n], distance[1][n]) << endl;

	return 0;
}
