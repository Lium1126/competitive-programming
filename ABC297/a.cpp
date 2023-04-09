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
	ll ans = -1;
	ll n, d;
	cin >> n >> d;
	vector<ll> t(n);
	rep(i, n) cin >> t[i];

	for (ll i = 1;i < n;i++) {
		if (t[i] - t[i - 1] <= d && ans == -1) ans = t[i];
	}

	cout << ans << endl;

	return 0;
}