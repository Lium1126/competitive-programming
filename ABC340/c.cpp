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

map<ll, ll> m;

ll solve(ll x) {
	if (m.find(x) != m.end()) return m[x];

	ll tmp = 0;

	ll down = x / 2;
	ll up = x / 2 + x % 2;

	if (down <= 1 && up <= 1) {
		return m[x] = x;
	} else if (down == up) {
		tmp += 2 * solve(down);
	} else {
		if (down >= 2) tmp += solve(down);
		if (up >= 2) tmp += solve(up);
	}

	return m[x] = x + tmp;
}

int main() {
	ll n;
	cin >> n;

	cout << solve(n) << endl;;

	return 0;
}