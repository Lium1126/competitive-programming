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
	ll N, u, v;
	cin >> N;

	ll M_G, M_H;
	cin >> M_G;

	set<P> G, H;
	rep(i, M_G) {
		cin >> u >> v;
		u--, v--;
		G.insert(P{u, v});
		G.insert(P{v, u});
	}

	cin >> M_H;
	rep(i, M_H) {
		cin >> u >> v;
		u--, v--;
		H.insert(P{u, v});
		H.insert(P{v, u});
	}

	vector<vector<ll>> A(N, vector<ll>(N));
	for (ll i = 0;i < N - 1;i++) {
		for (ll j = i + 1;j < N;j++) {
			cin >> A[i][j];
			A[j][i] = A[i][j];
		}
	}

	ll ans = __LONG_LONG_MAX__;
	vector<ll> index(N);
	rep(i, N) index[i] = i;
	do {
		ll tmp = 0;

		for (ll i = 0;i < N - 1;i++) {
			for (ll j = i + 1;j < N;j++) {
				bool G_contain = G.find(P{i, j}) != G.end();
				bool H_contain = H.find(P{index[i], index[j]}) != H.end();

				tmp += A[index[i]][index[j]] * (G_contain ^ H_contain);
			}
		}

		ans = min(ans, tmp);
	} while (next_permutation(index.begin(), index.end()));

	cout << ans << endl;

	return 0;
}
