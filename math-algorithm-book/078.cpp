#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> ans(n + 1, -1);
	vector<vector<ll>> g(n + 1, vector<ll>(0));

	ll a, b;
	rep(i, m) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	queue<ll> que;
	ans[1] = 0;
	que.push(1LL);
	while(!que.empty()) {
		ll now = que.front(); que.pop();
		for (ll next : g[now]) {
			if (ans[next] == -1) {
				ans[next] = ans[now] + 1;
				que.push(next);
			}
		}
	}

	for (ll i = 1;i <= n;i++) cout << (ans[i] == -1 ? 120 : min(120LL, ans[i])) << endl;;

	return 0;
}