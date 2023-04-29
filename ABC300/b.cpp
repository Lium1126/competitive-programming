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

ll h, w;
vector<string> shift(vector<string> b, ll s, ll t) {
	// vertical
	irep(cnt, s) {
		rep(j, w) {
			char tmp = b[0][j];
			rep(i, h) {
				if (i == h-1) b[i][j] = tmp;
				else b[i][j] = b[i+1][j];
			}
		}
	}

	irep(cnt, t) {
		rep(i, h) {
			char tmp = b[i][0];
			rep(j, w) {
				if (j == w-1) b[i][j] = tmp;
				else b[i][j] = b[i][j+1];
			}
		}
	}

	return b;
}

bool same(vector<string> a, vector<string> b) {
	bool ret = true;
	rep(i, h) {
		if (a[i] != b[i]) ret = false;
	}
	return ret;
}

int main() {
	cin >> h >> w;

	vector<string> a(h), b(h);

	rep(i, h) cin >> a[i];
	rep(i, h) cin >> b[i];

	bool f = false;
	rep(t, w) {
		rep(s, h) {
			// Bをシフト
			vector<string> B;
			B = shift(b, s, t);

			if (same(a, B)) f = true;

//			cout << s << ' ' << t << endl;
//			rep(i, h) cout << B[i] << endl;
		}
	}

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}