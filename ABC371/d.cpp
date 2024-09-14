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
	ll n;
	cin >> n;

	vector<ll> x(n), p(n);
	vector<ll> sum(n + 1, 0);

	rep(i, n) cin >> x[i];
	rep(i, n) {
		cin >> p[i];
		sum[i + 1] = sum[i] + p[i];
	}

	ll q;
	cin >> q;

	ll l, r;
	while (q--) {
		cin >> l >> r;
		auto litr = lower_bound(x.begin(), x.end(), l);
		auto ritr = upper_bound(x.begin(), x.end(), r);

		cout << sum[(ritr - x.begin())] - sum[(litr - x.begin())] << endl;
	}

	return 0;
}