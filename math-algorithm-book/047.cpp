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
vector<vector<ll> > g(200009, vector<ll>(0));
vector<ll> color(200009, -1);

bool dfs(ll pos, ll c) {
	color[pos] = c;
	bool ret = true;
	for (ll next : g[pos]) {
		if (color[next] != -1) {
			if (color[next] == c) return false;
			continue;
		}

		ret &= dfs(next, (c + 1) % 2);
	}

	return ret;
}

int main() {
	cin >> n >> m;

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	bool ans = true;
	for (ll i = 1;i <= n && ans;i++) {
		if (color[i] == -1) ans &= dfs(i, 0);
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}