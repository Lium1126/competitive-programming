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
	ll n, m, ans = __LONG_LONG_MAX__;
	cin >> n >> m;

	irep(i, n) {
		ll x = (m + i - 1) / i;
		if (x <= n) ans = min(ans, i * x);
		if (i > x) break;
	}

	cout << (ans == __LONG_LONG_MAX__ ? -1 : ans) << endl;

	return 0;
}