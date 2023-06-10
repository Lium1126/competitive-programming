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
	cin >> h >> w;

	vector<string> m(h);
	rep(i, h) cin >> m[i];

	ll dx[4] = {-1, 0, 1, 0};
	ll dy[4] = {0, -1, 0, 1};
	P ans;
	rep(i, h) {
		rep(j, w) {
			if (m[i][j] == '.') {
				ll tmp = 0;
				rep(cnt, 4) {
					ll nx = dx[cnt] + j;
					ll ny = dy[cnt] + i;

					if (0 <= nx && nx < w && 0 <= ny && ny < h && m[ny][nx] == '#') tmp++;
				}
				if (tmp >= 2) ans = P{i, j};
			}
		}
	}

	cout << ans.first + 1 << ' ' << ans.second + 1 << endl;

	return 0;
}