#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll h, w;
	cin >> h >> w;

	ll sx, sy, gx, gy;
	cin >> sy >> sx;
	cin >> gy >> gx;
	sx--; sy--; gx--; gy--;

	vector<string> maps(h);
	vector<vector<ll> > dist(h, vector<ll>(w, -1));
	rep(i, h) cin >> maps[i];

	queue<P> que;
	que.push(P{sx, sy});
	dist[sy][sx] = 0;
	
	ll dx[4] = {0, 1, 0, -1};
	ll dy[4] = {1, 0, -1, 0};

	while(!que.empty()) {
		P now = que.front(); que.pop();
		rep(i, 4) {
			ll nx = now.first + dx[i];
			ll ny = now.second + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && maps[ny][nx] == '.') {
				dist[ny][nx] = dist[now.second][now.first] + 1;
				maps[ny][nx] = '#';
				que.push(P{nx, ny});
			}
		}
	}

	cout << dist[gy][gx] << endl;

	return 0;
}