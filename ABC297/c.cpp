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

	vector<string> maps(h);
	rep(i, h) cin >> maps[i];

	rep(i, h) {
		for (ll j = 0;j < w - 1;j++) {
			if (maps[i][j] == 'T' && maps[i][j + 1] == 'T') {
				maps[i][j] = 'P';
				maps[i][j + 1] = 'C';
			}
		}
	}

	for (string s : maps) cout << s << endl;

	return 0;
}