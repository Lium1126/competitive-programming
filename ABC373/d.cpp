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

vector<ll> v(200005, __LONG_LONG_MAX__);
vector<bool> visited(200005, false);
vector<map<ll, ll>> edge(200005);
vector<map<ll, ll>> reversed_edge(200005);

void solve(ll now, ll value);
void reversed_solve(ll now, ll value);

int main() {
	ll n, m;
	cin >> n >> m;

	ll from, to, cost;
	rep(i, m) {
		cin >> from >> to >> cost;
		edge[from][to] = cost;
		reversed_edge[to][from] = cost;
	}

	irep(i, n) {
		if (!visited[i]) solve(i, 0);
	}

	irep(i, n) cout << min(v[i], 1000000000000000000LL) << ' ';
	cout << endl;

	return 0;
}

void reversed_solve(ll now, ll value) {
	if (visited[now]) return;

	v[now] = value;
	visited[now] = true;

	for (P p : reversed_edge[now]) {
		reversed_solve(p.first, value - p.second);
	}

	for (P p : edge[now]) {
		solve(p.first, value + p.second);
	}
}

void solve(ll now, ll value) {
	if (visited[now]) return;

	v[now] = value;
	visited[now] = true;

	for (P p : edge[now]) {
		solve(p.first, value + p.second);
	}

	for (P p : reversed_edge[now]) {
		reversed_solve(p.first, value - p.second);
	}
}
