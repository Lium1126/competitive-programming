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

typedef pair<ll, ll> P;

int main() {
	ll n, q;
	cin >> n >> q;

	ll t, a, b;
	map<P, bool> g;
	rep (i, q) {
		cin >> t >> a >> b;
		P p = make_pair(a, b);
		P pb = make_pair(b, a);

		if (t == 1) g[p] = true;
		if (t == 2) g[p] = false;
		if (t == 3) cout << (g[p] && g[pb] ? "Yes" : "No") << endl;
	}

	return 0;
}