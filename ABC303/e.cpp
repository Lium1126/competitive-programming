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
	ll n;
	cin >> n;

	vector<set<ll>> g(n + 1);
	ll s, t;
	rep(i, n - 1) {
		cin >> s >> t;
		g[s].insert(t);
		g[t].insert(s);
	}

	queue<ll> que;
	vector<bool> visited(n + 1, false);
	que.push(1);
	while (!que.empty()) {
		ll now = que.front(); que.pop();
		visited[now] = true;

		vector<ll> rms;
		for (auto itr = g[now].begin();itr != g[now].end();itr++) {
			ll to = *itr;
			if (!visited[to]) {
				if (g[now].size() == 2 && g[to].size() == 2) {
					rms.push_back(to);
				}
				que.push(to);
			}
		}

		for (ll r : rms) {
			g[now].erase(r);
			g[r].erase(now);
		}
	}
/*
	irep(i, n) {
		cout << i << ": ";
		for (auto itr = g[i].begin();itr != g[i].end();itr++) {
			cout << *itr << ' ';
		}
		cout << endl;
	}
*/

	vector<ll> ans;
	ll cnt = 0;
	irep(i, n) {
		if (g[i].size() >= 2) {
			ans.push_back(g[i].size());
			cnt += (1 + g[i].size());
		}
	}
	
	// cout << n - cnt << endl;
	rep(i, (n - cnt) / 3) ans.push_back(2);

	sort(ans.begin(), ans.end());

	for (ll out : ans) {
		cout << out << ' ';
	}
	cout << endl;

	return 0;
}