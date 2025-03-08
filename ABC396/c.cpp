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
	ll n, m;
	cin >> n >> m;

	vector<ll> b(n), w(m);
	rep(i, n) cin >> b[i];
	rep(i, m) cin >> w[i];

	sort(b.begin(), b.end(), greater<ll>());
	sort(w.begin(), w.end(), greater<ll>());

	set<ll> idx;
	rep(i, n) idx.insert(i);

	ll ans = 0;
	rep(i, max(n, m)) {
		if (i >= n) continue;
		ll black = b[i];
		ll white = (i >= m) ? 0 : w[i];
		if (white < 0 || black + white < 0) continue;
		ans += black + white;
		idx.erase(i);
	}

	for (auto i : idx) {
		if (b[i] > 0) ans += b[i];
	}

	cout << ans << endl;

	return 0;
}