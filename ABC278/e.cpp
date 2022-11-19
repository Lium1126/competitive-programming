#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll H, W, N, h, w;
	cin >> H >> W >> N >> h >> w;

	vector<vector<ll>> v(H, vector<ll>(W));
	vector<vector<P>> g(301, vector<P>());
	set<ll> colors;
	rep(i, H) rep(j, W) {
		cin >> v[i][j];
		colors.insert(v[i][j]);
		g[v[i][j]].push_back(make_pair(i, j));
	}

	for (ll i = 0;i <= H - h;i++) {
		for (ll j = 0;j <= W - w;j++) {
			ll cnt = 0;
			for (auto itr = colors.begin();itr != colors.end();itr++) {
				bool flag = true;
				for (P p : g[*itr]) {
					if (!(i <= p.first && p.first <= i + h - 1 && j <= p.second && p.second <= j + w - 1)) flag = false;
				}
				if (flag) cnt++;
			}

			cout << colors.size() - cnt << ' ';
		}
		cout << endl;
	}

	return 0;
}