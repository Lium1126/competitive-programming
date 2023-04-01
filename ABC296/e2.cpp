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

	vector<bool> returnable(n + 1, false);
	vector<ll> g(n + 1), indeg(n + 1, 0);
	irep(i, n) {
		cin >> g[i];
		indeg[g[i]]++;
	}

	queue<ll> que;
	irep(i, n) {
		if (indeg[i] == 0) que.push(i);
	}

	vector<ll> s;
	while (!que.empty()) {
		ll v = que.front(); que.pop();
		s.push_back(v);
		indeg[g[v]]--;
		if (indeg[g[v]] == 0) que.push(g[v]);
	}
	

	ll ans = 0;
	irep(i, n) {
		if (returnable[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}