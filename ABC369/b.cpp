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

	vector<ll> l, r;
	char c;
	ll in, lcnt = 0, rcnt = 0;
	rep(i, n) {
		cin >> in >> c;
		if (c == 'L') l.push_back(in), lcnt++;
		else r.push_back(in), rcnt++;
	}

	ll ans = 0;
	rep(i, lcnt - 1) ans += abs(l[i] - l[i + 1]);
	rep(i, rcnt - 1) ans += abs(r[i] - r[i + 1]);

	cout << ans << endl;

	return 0;
}