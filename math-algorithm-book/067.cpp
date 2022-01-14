#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll h, w;
	cin >> h >> w;

	vector<vector<ll>> a(h, vector<ll>(w));
	vector<ll> hor(h, 0), ver(w, 0);

	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			hor[i] += a[i][j];
			ver[j] += a[i][j];
		}
	}

	rep(i, h) rep(j, w) cout << hor[i] + ver[j] - a[i][j] << (j != w - 1 ? ' ' : '\n');

	return 0;
}