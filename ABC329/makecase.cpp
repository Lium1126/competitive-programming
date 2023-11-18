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
	ll n = 100000;
	ll q = 200000;
	cout << n << ' ' << q << endl;

	rep(i, n) {
		cout << 1 << (i != n - 1 ? ' ' : '\n');
	}

	rep(i, n - 1) {
		cout << i + 2 << ' ' << 1 << endl;
	}

	ll last = 1;
	rep(i, q - (n - 1)) {
		ll tmp = last;
		while (last == tmp) tmp = rand() % n + 1;
		cout << last << ' ' << tmp << endl;
		last = tmp;
	}

	return 0;
}