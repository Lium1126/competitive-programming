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

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, -1, 0, 1};

int main() {
	ll h, w, d;
	cin >> h >> w >> d;
	vector<string> m(h);
	vector<P> hu;
	rep(i, h) {
		cin >> m[i];
		rep(j, w) if (m[i][j] == 'H') hu.push_back(P{i, j});
	}
	ll ans = 0;

	vector<vector<bool>> hurmided(h, vector<bool>(w, false));
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	queue<PP> que;
	for (P tmp :  hu) que.push(PP{tmp, 0});
	while (!que.empty()) {
		PP now = que.front(); que.pop();
		visited[now.first.first][now.first.second] = true;
		hurmided[now.first.first][now.first.second] = true;
		rep(i, 4) {
			ll ny = now.first.first + dy[i];
			ll nx = now.first.second + dx[i];
			if (0 <= ny && ny < h && 0 <= nx && nx < w && m[ny][nx] == '.' && now.second + 1 <= d && !visited[ny][nx]) {
				que.push(PP{P{ny, nx}, now.second + 1});
			}
		}
	}

	rep(i, h) rep(j, w) ans += hurmided[i][j] ? 1 : 0;
	cout << ans << endl;

	return 0;
}