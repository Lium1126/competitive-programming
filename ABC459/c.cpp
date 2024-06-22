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
	ll x1, x2, y1, y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;

	ll ydist = abs(y1 - y2);
	ll xdist = abs(x1 - x2);
	if (ydist >= xdist) cout << ydist << endl;
	else {
		ll diff = xdist - ydist;
		if (ydist == 0) {
			ll tmp1, tmp2;
			if (y1 % 2) tmp1 = ydist + diff / 2 + (min(x1, x2) % 2 == 0? 1 : 0);
			else tmp1 = ydist + diff / 2 + (min(x1, x2) % 2 != 0? 1 : 0);
			if (y2 % 2) tmp2 = ydist + diff / 2 + (min(x1, x2) % 2 == 0? 1 : 0);
			else tmp2 = ydist + diff / 2 + (min(x1, x2) % 2 != 0? 1 : 0);
			cout << min(tmp1, tmp2) << endl;
		} else {
			cout << ydist + diff / 2 << endl;
		}
	}

	return 0;
}