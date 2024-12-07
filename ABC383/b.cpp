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

vector<string> m(15);
ll h, w, d;
ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};
vector<P> f;

ll dist(P a, P b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

ll solve(P a, P b) {
	ll ans = 0;
	for (P elem : f) {
		if (dist(elem, a) <= d || dist(elem, b) <= d) ans++;
	}
	return ans;
}

int main() {
	cin >> h >> w >> d;

	rep(i, h) {
		cin >> m[i];
		rep(j, w) if (m[i][j] == '.') f.push_back(P{i, j});
	}

	ll ans = 0;
	rep(i, f.size()) {
		for (ll j = i + 1;j < f.size();j++) {
			ans = max(ans, solve(f[i], f[j]));
		}
	}

	cout << ans << endl;

	return 0;
}