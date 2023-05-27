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

bool nakayosi(ll i, ll j, vector<ll> v) {
	bool f = false;
	rep(idx, v.size() - 1) {
		if (v[idx] == i && v[idx + 1] == j ||
			v[idx] == j && v[idx + 1] == i) {
				f = true;
			}
	}
	return f;
}

int main() {
	ll n, m;
	cin >> n >> m;

	vector<vector<ll>> v(m, vector<ll>(n));
	rep(i, m) {
		rep(j, n) cin >> v[i][j];
	}

	ll ans = 0;
	irep(i, n - 1) {
		for (ll j = i + 1;j <= n;j++) {
			bool f = true;
			rep(cnt, m) {
				if (nakayosi(i, j, v[cnt])) f = false;
			}
			if (f) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}