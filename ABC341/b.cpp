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
	vector<ll> a(n), s(n), t(n);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n - 1) {
		cin >> s[i] >> t[i];
	}

	rep(i, n - 1) {
		if (a[i] >= s[i]) {
			a[i + 1] += (a[i] / s[i]) * t[i];
			a[i] %= s[i];
		}
	}

	cout << a[n - 1] << endl;
	return 0;
}