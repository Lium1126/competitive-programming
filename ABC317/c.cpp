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
typedef pair<P, ll> PP;

int main() {
	ll n, m;
	cin >> n >> m;

	ll a, b, c;
	vector<vector<ll>> G(n, vector<ll>(n, -1));
	rep(i, m) {
		cin >> a >> b >> c;
		a--, b--;
		G[a][b] = c;
		G[b][a] = c;
	}

	ll ans = -1;
	rep(s, n) {
	rep(g, n) {
	if (s == g) continue;

		ll tmp = -1;
		set<ll> empty;
		empty.insert(s);
		queue<pair<pair<ll, set<ll>>, ll>> que;
		que.push(make_pair(make_pair(s, empty), 0));
		while (!que.empty()) {
			pair<pair<ll, set<ll>>, ll> now = que.front(); que.pop();
			if (now.first.first == g) tmp = max(tmp, now.second);

			rep(i, n) {
				set<ll> stmp = now.first.second;
				if (G[now.first.first][i] != -1 && stmp.find(i) == stmp.end()) {
					stmp.insert(i);
					que.push(make_pair(make_pair(i, stmp), now.second + G[now.first.first][i]));
				}
			}
		}

		ans = max(ans, tmp);
	}
	}

	cout << ans << endl;

	return 0;
}