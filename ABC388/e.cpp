#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <ranges>
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

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll j = 0, d = 0;
	rep(i, n) {
		while (j < n && a[i] * 2 > a[j]) j++;
		d = max(d, j - i);

		if (i + max(d, i + 1) >= n) {
			cout << i << endl;
			return 0;
		}
	}

	return 0;
}