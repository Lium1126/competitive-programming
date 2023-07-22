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

int main() {
	ll n, m;
	cin >> n >> m;
	vector<string> maps(n);
	rep(i, n) cin >> maps[i];

	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));;
	P now = make_pair(1, 1);
	queue<PP> que;
	que.push(PP{now, 2});
	que.push(PP{now, 3});
	ll dx[4] = {-1, 0, 1, 0};
	ll dy[4] = {0, -1, 0, 1};
	while (!que.empty()) {
		PP tmp = que.front(); que.pop();
		if (!visited[tmp.first.first][tmp.first.second][tmp.second]) {
			visited[tmp.first.first][tmp.first.second][tmp.second] = true;
			P a = tmp.first;
			P next = P{a.first + dy[tmp.second], a.second + dx[tmp.second]};
			if (maps[next.first][next.second] == '.') { // 進行方向が岩じゃないならpush
				que.push(PP{next, tmp.second});
			} else {
				rep(i, 4) {
					if (tmp.second == i) continue;
					P next = P{a.first + dy[i], a.second + dx[i]};
					if (maps[next.first][next.second] == '.') {
						que.push(PP{next, i});
					}
				}
			}
		}
	}

	ll ans = 0;
	rep(i, n) {
		rep(j, m) {
			bool f = false;
			rep(k, 4) {
				f |= visited[i][j][k];
			}
			if (f) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}