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

ll power(ll n, ll x) {
	if (x == 0) return 1;
	if (x == 1) return n;
	if (x % 2 == 0) return  power(n * n, x / 2);
	else return power(n * n, x / 2) * n;
}

int main() {
	ll a = 1000000000LL;
	ll n, m;
	cin >> n >> m;

	for (ll i = 0;i <= m;i++) {
		a -= power(n, i);
		if (a < 0) {
			cout << "inf" << endl;
			return 0;
		}
	}

	cout << 1000000000LL - a << endl;

	return 0;
}