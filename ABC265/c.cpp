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

int main() {
	ll h, w;
	cin >> h >> w;

	vector<string> maps(h);
	vector<vector<bool>> flag(h, vector<bool>(w, false));
	rep(i, h) cin >> maps[i];

	ll i = 0, j = 0;
	while(1) {
/**
		cout << i + 1 << ' ' << j + 1 << endl;
		rep(H, h) {
			rep(W, w) {
				cout << (flag[H][W] ? '!' : '.');
			}
			cout << endl;
		}
**/
		if (flag[i][j]) {
			cout << "-1" << endl;
			return 0;
		}
		flag[i][j] = true;
		if (maps[i][j] == 'U' && i != 0) i--;
		else if (maps[i][j] == 'D' && i != h - 1) i++;
		else if (maps[i][j] == 'L' && j != 0) j--;
		else if (maps[i][j] == 'R' && j != w - 1) j++;
		else break;
	}

	cout << i + 1 << ' ' << j + 1 << endl;

	return 0;
}