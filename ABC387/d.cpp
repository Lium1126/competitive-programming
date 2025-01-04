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
typedef pair<P, pair<bool, ll>> PP;

int main() {
	ll h, w;
	cin >> h >> w;

	vector<string> m(h), tmp(h);
	vector<vector<ll>> d1(h, vector<ll>(w, -1)), d2(h, vector<ll>(w, -1));
	P s, g;
	rep(i, h) {
		cin >> m[i];
		rep(j, w) {
			if (m[i][j] == 'S') s = P(i, j);	
			else if (m[i][j] == 'G') g = P(i, j);
		}
	}

	ll dx[4] = {1, -1, 0, 0};
	ll dy[4] = {0, 0, 1, -1};

	queue<PP> que1, que2;
	que1.push(PP(s, P(false, 0)));
	d1[s.first][s.second] = 0;
	tmp = m;
	tmp[s.first][s.second] = '#';
	while (!que1.empty()) {
		PP p = que1.front(); que1.pop();
		d1[p.first.first][p.first.second] = p.second.second;
		tmp[p.first.first][p.first.second] = '#';

		ll start = p.second.first ? 0 : 2;
		ll end = p.second.first ? 1 : 3;
		for (ll i = start;i <= end;i++) {
			ll nx = p.first.first + dx[i];
			ll ny = p.first.second + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && tmp[nx][ny] != '#') {
				que1.push(PP(P(nx, ny), P(!p.second.first, p.second.second + 1)));
				tmp[nx][ny] = '#';
			}
		}
	}

	que2.push(PP(s, P(false, 0)));
	d2[s.first][s.second] = 0;
	tmp = m;
	tmp[s.first][s.second] = '#';
	while (!que2.empty()) {
		PP p = que2.front(); que2.pop();
		d2[p.first.first][p.first.second] = p.second.second;
		tmp[p.first.first][p.first.second] = '#';

		ll start = p.second.first ? 0 : 2;
		ll end = p.second.first ? 1 : 3;
		for (ll i = start;i <= end;i++) {
			ll nx = p.first.first + dx[i];
			ll ny = p.first.second + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w && tmp[nx][ny] != '#') {
				que2.push(PP(P(nx, ny), P(!p.second.first, p.second.second + 1)));
				tmp[nx][ny] = '#';
			}
		}
	}

	if (d1[g.first][g.second] == -1 && d2[g.first][g.second] == -1) cout << -1 << endl;
	else if (d1[g.first][g.second] == -1) cout << d2[g.first][g.second] << endl;
	else if (d2[g.first][g.second] == -1) cout << d1[g.first][g.second] << endl;
	else cout << min(d1[g.first][g.second], d2[g.first][g.second]) << endl;

	return 0;
}