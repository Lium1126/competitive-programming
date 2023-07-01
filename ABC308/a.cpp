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
	bool f = true;
	ll prev = -1;
	ll in;
	rep(i, 8) {
		cin >> in;
		if (in < prev) f = false;
		if (in < 100 || 675 < in) f = false;
		if (in % 25 != 0) f = false;
		prev = in;
	}
	cout << (f ? "Yes" : "No") << endl;
	return 0;
}