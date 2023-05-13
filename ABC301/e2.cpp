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
typedef pair<P, ll> Pl;

ll h, w, t;
vector<vector<ll>> p(18, vector<ll>(18, 0));
vector<P> candy;

ll path(P s, P g, vector<string> maps) {
//	cout << "(" << s.first << ", " << s.second << ") -> (" << g.first << ", " << g.second << ")" << endl;
	vector<ll> dx{1, 0, -1, 0};
	vector<ll> dy{0, 1, 0, -1};

	queue<Pl> que;
	que.push(Pl{s, 0});
	while (!que.empty()) {
		Pl now = que.front(); que.pop();
		if (now.first == g) return now.second;
		maps[now.first.first][now.first.second] = '#';

		rep(i, 4) {
			ll nx = now.first.second + dx[i];
			ll ny = now.first.first + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && maps[ny][nx] != '#') {
				que.push(Pl{P{ny, nx}, now.second + 1});
			}
		}
	}

	return -1;
}

ll solve(set<ll> can, ll len, ll now, ll cnt) {
	if (now == candy.size() - 1) return cnt;
	ll rec = 0;
	for (auto elem : can) {
		if (p[now][elem] + len <= t) {
			set<ll> tmp = can;
			tmp.erase(elem);
//			cout << now << "->" << elem << "(" << len << "+" << p[now][elem] << ")" << endl;
			if (elem != candy.size() - 1) rec = max(rec, solve(tmp, len + p[now][elem], elem, cnt + 1));
			else rec = rec = max(rec, solve(tmp, len + p[now][elem], elem, cnt));
		}
	}
	return rec;
}

int main() {
	cin >> h >> w >> t;
	vector<string> maps(h);
	rep(i, h) cin >> maps[i];

	P s, g;
	rep(i, h) {
		rep(j, w) {
			if (maps[i][j] == 'o') candy.push_back(P{i, j});
			if (maps[i][j] == 'S') s = P{i, j};
			if (maps[i][j] == 'G') g = P{i, j};
		}
	}

	candy.insert(candy.begin(), s);
	candy.push_back(g);
//	for (ll o : cg) cout << o << ' ';
//	cout << endl;

	rep(i, candy.size()) {
		for (ll j = i + 1;j < candy.size();j++) {
			p[i][j] = p[j][i] = path(candy[i], candy[j], maps);
		}
	}

/*
	rep(i, candy.size()) {
		rep(j, candy.size()) {
			cout << p[i][j] << ' ';
		}
		cout << endl;
	}
*/

	ll ans = -1;
	set<ll> st;
	irep(i, candy.size() - 1) st.insert(i);
	ans = solve(st, 0, 0, 0);
	cout << (ans == 0 ? -1 : ans) << endl;

	return 0;
}