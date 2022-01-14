#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<double> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	double ans = 0;
	rep(i, n) {
		ans += a[i] / 3 + (2 * b[i]) / 3;
	}

	printf("%.6lf\n", ans);

	return 0;
}