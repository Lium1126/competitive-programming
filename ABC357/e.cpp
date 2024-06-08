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

vector<ll> dst(200005, 0);
vector<ll> reach(200005, -1);
vector<bool> cycle(200005, false);
vector<bool> visited(200005, false);

ll cycle_path(ll start, ll now, ll cnt) {
	cnt++;
	cycle[now] = true;
	if (now == start) return cnt;
	else return cycle_path(start, dst[now], cnt);
}

ll solve(ll now) {
	visited[now] = true;
	ll tmp = -1;

	if (!visited[dst[now]]) {
		tmp = solve(dst[now]);
	} else {
		if (reach[dst[now]] != -1) tmp = reach[dst[now]];
		else tmp = cycle_path(now, dst[now], 0);
	}

	if (cycle[now]) {
		return reach[now] = tmp;
	} else {
		return reach[now] = tmp + 1;
	}
}

int main() {
	ll n;
	cin >> n;
	irep(i, n) cin >> dst[i];

	irep(i, n) {
		if (!visited[i]) {
			// cout << i << endl;
			solve(i);
		}
	}

	ll ans = 0;
	irep(i, n) {
		// cout << i << ": " << reach[i] << endl;
		ans += reach[i];
	}

	cout << ans << endl;

	return 0;
}