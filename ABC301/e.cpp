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

int main() {
	ll h, w, t;
	cin >> h >> w >> t;

	P s, g;
	vector<string> maps(h);
	rep(i, h) cin >> maps[i];

	rep(i, h) {
		rep(j, w) {
			if (maps[i][j] == 'S') s = P{i, j};
			if (maps[i][j] == 'G') g = P{i, j};
		}
	}

	ll ans = -1;
	queue<PP> que;
	que.push(PP{s, P{0, 0}});
	vector<ll> dx{1, 0, -1, 0};
	vector<ll> dy{0, 1, 0, -1};
	while (!que.empty()) {
		PP now = que.front(); que.pop();
		if (now.first == g) ans = max(ans, now.second.second);
		if (ans == 18) break;

		rep(i, 4) {
			ll nx = now.first.second + dx[i];
			ll ny = now.first.first + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && maps[ny][nx] != '#' && now.second.first + 1 <= t) {
				if (maps[ny][nx] == 'o') que.push(PP{P{ny, nx}, P{now.second.first + 1, now.second.second + 1}});
				else que.push(PP{P{ny, nx}, P{now.second.first + 1, now.second.second}});
			}
		}
	}

	cout << ans << endl;

	return 0;
}