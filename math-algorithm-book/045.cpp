#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;

	vector<vector<ll> > g(100009, vector<ll>(0));
	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	ll ans = 0;
	for (ll i = 1;i <= n;i++) {
		ll cnt = 0;
		for (ll j : g[i]) if (j < i) cnt++;
		if (cnt == 1) ans++;
	}

	cout << ans << endl;

	return 0;
}