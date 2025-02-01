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
typedef pair<ll, P> PP;

int main() {
	ll n, w;
	cin >> n >> w;

	vector<ll> time_to_erase(n + 1, __LONG_LONG_MAX__);

	vector<vector<P>> v(w + 1);
	ll x, y;
	irep(i, n) {
		cin >> x >> y;
		v[x].push_back(P(y, i));
	}

	irep(i, w) sort(v[i].begin(), v[i].end());

	// irep(i, w) {
	// 	for (auto p: v[i]) cout << p.second << ' ';
	// 	cout << endl;
	// }

	vector<deque<P>> dq(w + 1);
	irep(i, w) for (auto p: v[i]) dq[i].push_back(p);

	bool exit = false;
	while (!exit) {
		ll time = 0;

		irep(i, w) {
			if (dq[i].empty()) {
				exit = true;
				break;
			}

			time = max(time, dq[i].front().first);
		}
		if (exit) break;

		irep(i, w) {
			P target = dq[i].front();
			dq[i].pop_front();
			time_to_erase[target.second] = time;
		}
	}

	// irep(i, n) cout << i << ": " << time_to_erase[i] << endl;

	ll q, t, a;
	cin >> q;
	while (q--) {
		cin >> t >> a;
		cout << (t < time_to_erase[a] ? "Yes" : "No") << endl;
	}

	return 0;
}