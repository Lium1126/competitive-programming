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
typedef pair<P, P> PP;

vector<vector<ll>> g(200005);
vector<vector<vector<ll>>> info(200005);
vector<ll> ans(200005, -1);

void solve(ll limit, ll station, ll from) {
	ll leave = -1;
	for (vector<ll> train : info[station]) {
		// この電車がlimitまでにfromに到着できる最大の時間を求める
		if (train[5] != from) continue;
		ll l = train[0], d = train[1], k = train[2], c = train[3];
		ll t = limit - c - l;
		if (t < 0) continue;
		ll maxk = min(k - 1, t / d);
		leave = max(leave, l + maxk * d);
	}

	if (leave < 0) return;

	ans[station] = max(ans[station], leave);
	for (ll next : g[station]) {
		solve(leave, next, station);
	}
}

int main() {
	ll n, m;
	cin >> n >> m;

	ll l, d, k, c, a, b;
	rep(i, m) {
		cin >> l >> d >> k >> c >> a >> b;
		info[a].push_back({l, d, k, c, a, b});
		g[b].push_back(a);
	}

	for (ll next : g[n]) {
		solve(__LONG_LONG_MAX__, next, n);
	}
	irep(i, n - 1) {
		if (ans[i] == -1) cout << "Unreachable" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}