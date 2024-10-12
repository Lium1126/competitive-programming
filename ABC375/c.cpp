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

ll n;

P solve(P p, ll cnt) {
	if (cnt == 0) return p;
	return solve(P{p.second, n + 1 - p.first}, cnt - 1);
}

int main() {
	cin >> n;

	vector<string> m(n + 1), c(n + 1);
	vector<vector<ll>> v(n + 1, vector<ll>(n + 1, 0));
	irep(i, n) cin >> m[i];
	irep(i, n) m[i] = 'x' + m[i];
	c = m;

    int layers = n / 2;
    for (int layer = 0; layer < layers; ++layer) {
        for (int i = layer + 1; i <= n - layer; ++i) {
            v[layer + 1][i] = layer + 1;
            v[n - layer][i] = layer + 1;
            v[i][layer + 1] = layer + 1;
            v[i][n - layer] = layer + 1;
        }
    }

	// irep(i, n) {
	// 	irep(j, n) cout << v[i][j] << ' ';
	// 	cout << endl;
	// }

	irep(i, n) {
		irep(j, n) {
			P dst = solve(P{i, j}, v[i][j]);
			// cout << i << ' ' << j << "(" << v[i][j] << "): " << dst.first << ' ' << dst.second << endl;
			c[dst.first][dst.second] = m[i][j];
		}
	}

	irep(idx, n) {
		for (ll j = 1;j <= n;j++) cout << c[idx][j];
		cout << endl;
	}

	return 0;
}
