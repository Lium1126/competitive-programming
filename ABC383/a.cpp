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


	ll now = 0;
	vector<ll> t(n), v(n);

	rep(i, n) {
		cin >> t[i] >> v[i];
	}

	ll w = 0;
	rep(i, n) {
		now = t[i];
		if (i != 0) w = max(0LL, w - (now - t[i - 1]));
		w += v[i];
		// cout << now << ' ' << w << endl;
	}

	cout << w << endl;

	return 0;
}