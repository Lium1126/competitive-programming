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
	vector<ll> h(3), w(3);
	vector<vector<ll>> vec(3, vector<ll>(3, 0));
	rep(i, 3) cin >> h[i];
	rep(i, 3) cin >> w[i];

	ll ans = 0;
	for (ll i1 = 1;i1 <= 30;i1++) {
		for (ll i2 = 1;i2 <= 30;i2++) {
			for (ll i3 = 1;i3 <= 30;i3++) {
				for (ll i4 = 1;i4 <= 30;i4++) {
					vec[0][0] = i1; vec[0][1] = i2; vec[1][0] = i3; vec[1][1] = i4;
					if (h[0] - (vec[0][0] + vec[0][1]) <= 0) continue;
					if (h[1] - (vec[1][0] + vec[1][1]) <= 0) continue;
					if (w[0] - (vec[0][0] + vec[1][0]) <= 0) continue;
					if (w[1] - (vec[0][1] + vec[1][1]) <= 0) continue;
					vec[0][2] = h[0] - (vec[0][0] + vec[0][1]);
					vec[1][2] = h[1] - (vec[1][0] + vec[1][1]);
					vec[2][0] = w[0] - (vec[0][0] + vec[1][0]);
					vec[2][1] = w[1] - (vec[0][1] + vec[1][1]);

					vec[2][2] = h[2] - (vec[2][0] + vec[2][1]);
					if (vec[2][2] > 0 && vec[0][2] + vec[1][2] + vec[2][2] == w[2]) {
						/*
						cout << "---" << endl;
						rep(i, 3) {
							rep(j, 3) cout << vec[i][j] << ' ';
							cout << endl;
						}
						*/

						ans++;
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}