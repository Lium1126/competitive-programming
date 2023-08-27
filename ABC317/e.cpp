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
	ll h, w;
	cin >> h >> w;

	string S = "";
	rep(i, w) S += '.';

	vector<string> tmp(h, S);
	vector<string> maps(h);
	rep(i, h) cin >> maps[i];

	ll dx[4] = {0, 1, 0, -1};
	ll dy[4] = {-1, 0, 1, 0};
	P s, g;
	rep(i, h) {
		rep(j, w) {
			if (maps[i][j] == '#') tmp[i][j] = '#';

			if (maps[i][j] == '^') {
				tmp[i][j] = '#';
				ll y = i - 1;
				while (y >= 0 && maps[y][j] == '.') {
					tmp[y][j] = '#';
					y--;
				}
			}

			if (maps[i][j] == 'v') {
				tmp[i][j] = '#';
				ll y = i + 1;
				while (y < h && maps[y][j] == '.') {
					tmp[y][j] = '#';
					y++;
				}
			}

			if (maps[i][j] == '>') {
				tmp[i][j] = '#';
				ll x = j + 1;
				while (x < w && maps[i][x] == '.') {
					tmp[i][x] = '#';
					x++;
				}
			}

			if (maps[i][j] == '<') {
				tmp[i][j] = '#';
				ll x = j - 1;
				while (x >= 0 && maps[i][x] == '.') {
					tmp[i][x] = '#';
					x--;
				}
			}

			if (maps[i][j] == 'S') s = P{i, j};
			if (maps[i][j] == 'G') g = P{i, j};
		}
	}

	queue<PP> que;
	que.push(PP{s, 0});
	while (!que.empty()) {
		PP now = que.front(); que.pop();
		if(now.first == g) {
			cout << now.second << endl;
			return 0;
		}
		tmp[now.first.first][now.first.second] = '#';
		rep(i, 4) {
			ll nx = now.first.second + dx[i];
			ll ny = now.first.first + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && tmp[ny][nx] == '.') {
				que.push(PP{P{ny, nx}, now.second + 1});
			}
		}
	}

	cout << -1 << endl;

	return 0;
}