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
typedef pair<P, char> PP;

int main() {
	map<char, char> mp;
	mp['s'] = 'n';
	mp['n'] = 'u';
	mp['u'] = 'k';
	mp['k'] = 'e';
	mp['e'] = 's';

	ll h, w;
	cin >> h >> w;
	vector<string> maze(h);
	rep(i, h) {
		cin >> maze[i];
	}

	if (maze[0][0] != 's') {
		cout << "No" << endl;
		return 0;
	}

	queue<PP> que;
	que.push(PP{P{0, 0}, maze[0][0]});
	vector<vector<bool>> visited(h, vector<bool>(w, false));
	visited[0][0] = true;
	ll dx[4] = {-1, 0, 1, 0};
	ll dy[4] = {0, -1, 0, 1};
	while(!que.empty()) {
		PP now = que.front(); que.pop();
		visited[now.first.second][now.first.first] = true;
//		cout << "(" << now.first.first << ", " << now.first.second << ") " << now.second << endl;
		rep(i, 4) {
			P next = P{now.first.first + dx[i], now.first.second + dy[i]};
			if (0 <= next.first && next.first < w &&
				0 <= next.second && next.second < h && 
				visited[next.second][next.first] == false &&
				maze[next.second][next.first] == mp[now.second]) {
					visited[next.second][next.first] = true;
					que.push(PP{next, mp[now.second]});
				} 
		}
	}

	// rep(i, h) {
	// 	rep(j, w) {
	// 		cout << (visited[i][j] ? "#" : ".");
	// 	}
	// 	cout << endl;
	// }

	cout << (visited[h - 1][w - 1] ? "Yes" : "No") << endl;

	return 0;
}