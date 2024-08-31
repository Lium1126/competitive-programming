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

ll solve(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll ans = n;
	ll i = 0;
	while (i < n - 1) {
		ll d = a[i + 1] - a[i];
		ll cnt = 0;
		while (i + 1 + cnt < n && a[i + 1 + cnt] - a[i + cnt] == d) {
			cnt++;
		}
		ans += solve(cnt);
		// cout << i << ' ' << cnt << endl;
		i += cnt;
	}

	cout << ans << endl;

	return 0;
}