#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
typedef pair<ll, ll> P;

int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> t(n + 5, 0);
	rep(i, m) {
		ll l, r;
		cin >> l >> r;

		t[l]++;
		t[r + 1]--;
	}

	irep(i, n) {
		t[i] += t[i - 1];
	}

	ll ans = __LONG_LONG_MAX__;
	irep(i, n) {
		// cout << i << ": " << t[i] << endl;
		ans = min(ans, t[i]);
	}
	cout << ans << endl;

	return 0;
}
