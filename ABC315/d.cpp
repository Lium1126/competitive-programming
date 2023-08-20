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
	rep(i, h) cin >> m[i];

	vector<vector<ll>> tate(h, vector<ll>(26, 0));
	vector<vector<ll>> yoko(w, vector<ll>(26, 0));
	rep(i, h) {
		rep(j, w) {
			tate[i][m[i][j] - 'a']++;
			yoko[j][m[i][j] - 'a']++;
		}
	}

	// 行が消えるか
	vector<ll> tmp(26, 0);
	rep(i, h) {
		bool f = true;
		rep(j, w) {
			if (m[i][j] != m[i][0]) {
				f = false;
				break;
			}
		}

		if (f) {
			tmp[m[i][0] - 'a']++;
		}
	}

	rep(j, w) {
		rep(cnt , 26) {
			yoko[j][cnt] -= tmp[cnt];
		}
	}

	

	return 0;
}