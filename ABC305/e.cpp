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

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll a, b;
	vector<set<ll>> g(n + 1);

	rep(i, m) {
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
	}

	vector<P> guard(k);
	rep(i, k) {
		cin >> guard[i].second >> guard[i].first;
	}
	sort(guard.begin(), guard.end(), greater<P>());
	rep(i, k) swap(guard[i].first, guard[i].second);
//	for(P out : guard) cout << out.first << ' ' << out.second << endl;

	vector<bool> ans(n + 1, false);
	rep(cnt, k) {
		ll now = guard[cnt].first;
		ll limit = guard[cnt].second;
		queue<P> que;
		que.push(P{now, 0});
		while (!que.empty()) {
			P now = que.front(); que.pop();
			ans[now.first] = true;
			for (auto itr = g[now.first].begin();itr != g[now.first].end();itr++) {
				if (ans[*itr] == false && now.second + 1 <= limit) que.push(P{*itr, now.second + 1});
			}
		}
	}

	ll cnt = 0;
	for (ll i = 1;i <= n;i++) {
		if (ans[i]) cnt++;
	}
	cout << cnt << endl;
	for (ll i = 1;i <= n;i++) if (ans[i]) cout << i << ' ';
	cout << endl;

	return 0;
}