#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <climits>
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

ll n, m;
vector<vector<P>> g(15);

unsigned long long solve(ll now, ll visited, unsigned long long cost) {
	if (now  == n - 1) return cost;

	unsigned long long res = ULLONG_MAX;
	for (auto next : g[now]) {
		if (visited & (1 << next.first)) continue;
		res = min(res, solve(next.first, visited | (1 << next.first), cost ^ next.second));
	}

	return res;
}

int main() {
	cin >> n >> m;

	ll from, to, cost;
	rep(i, m) {
		cin >> from >> to >> cost;
		from--, to--;
		g[from].push_back(P(to, cost));
		g[to].push_back(P(from, cost));
	}

	cout << solve(0, 1, 0) << endl;

	return 0;
}