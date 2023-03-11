#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;

int main() {
	unsigned long long A, X, M;
	cin >> A >> X >> M;
	modint::set_mod(M);

	if (A == 1) {
		modint a(A);
		modint x(X);
		cout << (a * x).val() << endl;
	} else {
		modint a(A);
		modint x(X);

		modint tmp1(1 - a.pow(X));
		modint tmp2(1 - a);
		modint ans(tmp1 / tmp2);
		cout << ans.val() << endl;
	}

	return 0;
}