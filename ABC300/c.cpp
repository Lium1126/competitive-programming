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
	ll h, w;
	vector<string> c(105);

	cin >> h >> w;

	ll n = min(h, w);

	rep(i, h) cin >> c[i];

	vector<ll> ans(n+1);
	rep(i, h) {
		rep(j, w) {
			if (c[i][j] == '#') {
				ll tmp = 0;
				ll dx[4] = {-1, 1, -1, 1};
				ll dy[4] = {-1, -1, 1, 1};
				queue<P> que;
				que.push(P{i, j});
				while (!que.empty()) {
					P now = que.front(); que.pop();
					tmp++;
					c[now.first][now.second] = '.';

					rep(i, 4) {
						ll ny = now.first + dy[i];
						ll nx = now.second + dx[i];
						if (0 <= nx && nx < w && 0 <= ny && ny < h && c[ny][nx] == '#') 
							que.push(P{ny, nx});
					}
				}

				ans[(tmp - 1) / 4]++;
			}
		}
	}

	irep(i, n) cout << ans[i] << ' ';
	cout << endl;

	return 0;
}