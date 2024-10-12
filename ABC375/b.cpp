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
	P p = P{0, 0};

	ll x, y;
	double ans = 0.0;
	rep (i, n) {
		cin >> x >> y;
		ans += sqrt(pow((double)p.first - (double)x, 2.0) + pow((double)p.second - (double)y, 2.0));
		p = P{x, y};
	}
	ans += sqrt(pow((double)p.first, 2.0) + pow((double)p.second, 2.0));

	printf("%.12lf\n", ans);

	return 0;
}