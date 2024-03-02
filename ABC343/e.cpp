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
#define rep(i, n)	  for (ll i = 0;i < n;i++)
#define repf(i, n, f) for (ll i = 0;i < n && f;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

ll solve(ll x, ll y, ll z, ll a2, ll b2, ll c2, ll a3, ll b3, ll c3) {
	ll ret = 0;
	if ((0 <= x && x < 7) && (0 <= y && y < 7) && (0 <= z && z < 7)) ret++;
	if ((a2 <= x && x < a2 + 7) && (b2 <= y && y < b2 + 7) && (c2 <= z && z < c2 + 7)) ret++;
	if ((a3 <= x && x < a3 + 7) && (b3 <= y && y < b3 + 7) && (c3 <= z && z < c3 + 7)) ret++;
	return ret;
}

int main() {
	ll v1, v2, v3;
	cin >> v1 >> v2 >> v3;

	bool flag = true;
	repf(a2, 8, flag) {
	repf(b2, 8, flag) {
	repf(c2, 8, flag) {
	repf(a3, 8, flag) {
	repf(b3, 8, flag) {
	repf(c3, 8, flag) {

		ll tmp[] = {0, 0, 0};

		rep(x, 15) { 
		rep(y, 15) {
		rep(z, 15) {
			ll result = solve(x, y, z, a2, b2, c2, a3, b3, c3);
			if (result != 0) tmp[result - 1]++;
		}}}

		if (tmp[0] == v1 && tmp[1] == v2 && tmp[2] == v3) {
			flag = false;
			printf("Yes\n0 0 0 %lld %lld %lld %lld %lld %lld\n", a2, b2, c2, a3, b3, c3);
		}

	}}}}}}

	if (flag) cout << "No" << endl;

	return 0;
}