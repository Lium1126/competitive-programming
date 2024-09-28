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

	ll a, in_a, b, in_b;
	rep(i, n) {
		cin >> in_a;
		if (i == 0) a = in_a;
		a = max(a, in_a);
	}

	rep(i, n) {
		cin >> in_b;
		if (i == 0) b = in_b;
		b = max(b, in_b);
	}

	cout << a + b << endl;

	return 0;
}
