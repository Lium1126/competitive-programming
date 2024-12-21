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
	ll h, w, x, y;
	cin >> h >> w >> x >> y;
	x--, y--;
	vector<string> m(h);
	rep(i, h) cin >> m[i];
	string t;
	cin >> t;

	vector<vector<ll>> visited(h, vector<ll>(w, 0));

	P now = P{x, y};
	map<char, ll> dx, dy;
	dx['U'] = -1, dx['D'] = 1;
	dy['L'] = -1, dy['R'] = 1;
	for (char c : t) {
		P next = P{now.first + dx[c], now.second + dy[c]};
		if (0 <= next.first && next.first < h && 0 <= next.second && next.second < w && m[next.first][next.second] != '#') {
			if (m[next.first][next.second] == '@') visited[next.first][next.second] = 1;
			now = next;
		}
	}

	ll ans = 0;
	rep(i, h) rep(j, w) ans += visited[i][j];
	cout << now.first + 1 << ' ' << now.second + 1 << ' ' << ans << endl;
	
	return 0;
}