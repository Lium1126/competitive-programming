#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

vector<ll> root(200005, -1);
vector<vector<ll>> e(200005);
set<ll> close;

void dfs(ll r, ll now, ll prev) {
	root[now] = r;
	for (ll next : e[now]) if (prev != next && close.find(next) == close.end()) dfs(r, next, now);
}

int main() {
	ll n, s, t, q, x, y;
	cin >> n;
	vector<set<ll>> g(200005);

	irep(i, n) {
		cin >> s >> t;
		close.insert(i);
		g[s].insert(t); e[s].push_back(t);
		g[t].insert(s); e[t].push_back(s);
	}

	bool f = true;
	while (f) {
		bool f2 = false;
		irep(i, n) {
			if (g[i].size() == 1) {
				ll to = *(g[i].begin());
				g[i].erase(to);
				g[to].erase(i);
				close.erase(i);
				f2 = true;
			}
		}
		if (!f2) f = false;
	}

//	for (auto itr = close.begin();itr != close.end();itr++) cout << *itr << endl;

	for (auto itr = close.begin();itr != close.end();itr++) dfs(*itr, *itr, -1);
//	irep(i, n) cout << i << ":" << root[i] << endl;

	cin >> q;
	rep(i, q) {
		cin >> x >> y;
		cout << (root[x] == root[y] ? "Yes" : "No") << endl;
	}

	return 0;
}