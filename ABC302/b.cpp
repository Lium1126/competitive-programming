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
	string snuke = "snuke";

	rep(i, h) {
		cin >> m[i];
	}

	ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	rep(i, h) {
		rep(j, w) {
			if (m[i][j] == 's') {
				rep(dir, 8) {
					ll nowx = j;
					ll nowy = i;

					vector<P> tmp;
					tmp.push_back(P{i + 1, j + 1});
					string s_tmp = "s";

					irep(cnt, 4) {
						ll nx = nowx + dx[dir];
						ll ny = nowy + dy[dir];

						if (nx < 0 || nx >= w || ny < 0 || ny >= h) break;
						s_tmp += m[ny][nx];
						tmp.push_back(P{ny + 1, nx + 1});
						nowx = nx;
						nowy = ny;
					}

					if (tmp.size() == 5 && s_tmp == snuke) {
						for (P p : tmp) cout << p.first << ' ' << p.second << endl;
					}

				}
			}
		}
	}

	return 0;
}