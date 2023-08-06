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

	vector<ll> p(n);
	rep(i, n) cin >> p[i];

	ll m = p[0];
	bool f = false;
	for (ll i = 1;i < n;i++) {
		m = max(m, p[i]);
		if (p[i] == p[0]) f = true;
	}

	if (m == p[0]) {
		if (f) cout << 1 << endl;
		else cout << 0 << endl;
	}
    else cout << m - p[0] + 1 << endl;

	return 0;
}