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

vector<priority_queue<ll, vector<ll>, greater<ll>>> g(200005);
vector<bool> visited(200005, false);
vector<ll> ans;

void solve(ll now) {
	ans.push_back(now);
	visited[now] = true;

	while(!g[now].empty()) {
		ll next = g[now].top(); g[now].pop();
		if (visited[next]) continue;
		solve(next);
		ans.push_back(now);
	}

	return;
}

int main() {
	ll n;
	cin >> n;

	ll a, b;
	rep(i, n - 1) {
		cin >> a >> b;
		g[a].push(b);
		g[b].push(a);
	}

	solve(1);

	rep(i, ans.size()) {
		cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');
	}

	return 0;
}