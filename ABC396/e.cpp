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

vector<ll> nodes(200005, -1);
vector<vector<P>> g(200005);

void solve(ll now) {
	// TODO: Implement
}

int main() {
	ll n, m;
	cin >> n >> m;

	ll x, y, z;
	rep(i, m) {
		cin >> x >> y >> z;
		g[x].push_back(P(y, z));
		g[y].push_back(P(x, z));
	}

	rep(i, n) if (nodes[i] == -1) solve(i);

	bool flag = true;
	rep(i, n) if (nodes[i] == -1) flag = false;

	if (flag) {
		rep(i, n) cout << nodes[i] << ' ';
		cout << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}