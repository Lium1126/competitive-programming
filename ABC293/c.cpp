#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

typedef pair<ll, ll> P;
ll h, w;
vector<vector<ll>> maps(10, vector<ll>(10));

ll ans (vector<ll> path) {
	bool f = true;
	for (ll i = 1;i < path.size();i++) {
		for (ll j = 0;j < i;j++) {
			if (path[i] == path[j]) f = false;
		}
	}
	return (f ? 1 : 0);
}

ll solve(ll x, ll y, vector<ll> path) {
	if (x == w - 1 && y == h - 1) {
		return ans(path);
	}
	ll rec = 0;
	if (0 <= x + 1 && x + 1 < w && 0 <= y && y < h) {
		vector<ll> tmp = path;
		tmp.push_back(maps[y][x + 1]);
		rec += solve(x + 1, y, tmp);
	}
	if (0 <= x && x < w && 0 <= y + 1 && y + 1 < h) {
		vector<ll> tmp = path;
		tmp.push_back(maps[y + 1][x]);
		rec += solve(x, y + 1, tmp);
	}
	return rec;
}

int main() {
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> maps[i][j];
	vector<ll> path;

	path.push_back(maps[0][0]);
	cout << solve(0, 0, path) << endl;;

	return 0;
}