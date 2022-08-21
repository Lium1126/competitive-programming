#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
#define MOD 998244353

vector<ll> p(105), q(105);
ll n, d;

ll solve(ll cnt, ll pr, ll qr) {
	if (cnt == n) return 1;
	ll ret = 0;
	for (ll i = p[cnt] - d;i <= q[cnt] + d;i++) {
		ll pi = abs(p[cnt] - i);
		ll qi = abs(q[cnt] - i);
		if (pr + pi <= d && qr + qi <= d) ret = (ret + solve(cnt + 1, pr + pi, qr + qi)) % MOD;
	}
	return ret % MOD;
}

int main() {
	cin >> n >> d;
	rep(i, n) cin >> p[i];
	rep(i, n) cin >> q[i];
	rep(i, n) if (p[i] > q[i]) swap(p[i], q[i]);

	cout << solve(0, 0, 0) % MOD << endl;

	return 0;
}