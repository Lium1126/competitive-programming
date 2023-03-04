#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, m, u, v;
	ll ans = 0;
	cin >> n >> m;

	vector<set<ll>> e(n + 1);
	rep(i, m) {
		cin >> u >> v;
		e[u].insert(v);
	}

	irep(i, n) {
		vector<bool> visited(n + 1, false);
		set<ll> canarrive;
		queue<ll> que;
		que.push(i);

		while (!que.empty()) {
			ll now = que.front(); que.pop();
			visited[now] = true;
			canarrive.insert(now);
			for (auto itr = e[now].begin();itr != e[now].end();itr++) 
				if (!visited[*itr]) que.push(*itr);
		}

		//printf("%ld\n", i);
		for (auto itr = canarrive.begin();itr != canarrive.end();itr++) {
			if (i == *itr) continue;
			//printf("\t%ld\n", *itr);
			if (e[i].find(*itr) == e[i].end()) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}