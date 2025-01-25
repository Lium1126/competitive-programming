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
	ll b_min_x = __LONG_LONG_MAX__;
	ll b_max_x = 0;
	ll b_min_y = __LONG_LONG_MAX__;
	ll b_max_y = 0;
	rep(i, h) {
		cin >> m[i];
		rep(j, w) {
			if (m[i][j] == '#') {
				b_min_x = min(b_min_x, j);
				b_max_x = max(b_max_x, j);
				b_min_y = min(b_min_y, i);
				b_max_y = max(b_max_y, i);
			}
		}
	}

	for (ll i = b_min_y;i <= b_max_y;i++) {
		for (ll j = b_min_x;j <= b_max_x;j++) {
			if (m[i][j] == '.') {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}