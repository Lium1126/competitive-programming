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
	ll n, x;
	cin >> n >> x;

	vector<ll> a(n - 1);
	rep(i, n - 1) cin >> a[i];

	for (ll i = 0;i <= 100;i++) {
		vector<ll> b(n);
		rep(j, a.size()) b[j] = a[j];
		b[n - 1] = i;
		sort(b.begin(), b.end());
		ll p = 0;
		rep(j, n) {
			if (j == 0 || j == n - 1) continue;
			p += b[j];
		}

		if (p >= x) {
			cout << i << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}