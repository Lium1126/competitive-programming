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

vector<bool> visited(20005, false);
vector<set<ll>> g(20005);

void solve(ll now) {
	visited[now] = true;
	for (auto itr = g[now].begin();itr != g[now].end();itr++) {
		if (!visited[*itr]) solve(*itr);
	}
	return;
}

ll power(ll a) {
	return a * a;
}

int main() {
	ll n, d;
	cin >> n >> d;

	vector<P> p(n);
	rep(i, n) cin >> p[i].first >> p[i].second;

	rep(i, n) {
		for (ll j = i + 1;j < n;j++) {
			if (d * d >= power(p[i].first - p[j].first) + power(p[i].second - p[j].second)) {
				g[i].insert(j);
				g[j].insert(i);
			}
		}
	}
/*
	rep(i, n) {
		cout << i << ": ";
		for (auto itr = g[i].begin();itr != g[i].end();itr++) {
			cout << *itr << ' ';
		}
		cout << endl;
	}
*/

	solve(0);
	rep(i, n) cout << (visited[i] ? "Yes" : "No") << endl;

	return 0;
}