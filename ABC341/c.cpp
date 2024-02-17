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
	ll h, w, n;
	cin >> h >> w >> n;

	vector<string> maze(h);
	string s;
	cin >> s;
	rep(i, h) cin >> maze[i];

	ll ans = 0;
	ll dx[4] = {0, 1, 0, -1};
	ll dy[4] = {-1, 0, 1, 0};
	map<char, int> m = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
	rep(i, h) {
		rep(j, w) {
			bool f = true;
			ll y = i, x = j;
			if (maze[y][x] == '#') f = false;
			for(ll cnt = 0;cnt < n && f;cnt++) {
				y += dy[m[s[cnt]]];
				x += dx[m[s[cnt]]];
				if (maze[y][x] == '#') f = false;
			}

			if (f) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}