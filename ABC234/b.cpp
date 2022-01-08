#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<double, double> P;

double dist(P a, P b) {
	P tmp = P{abs(a.first - b.first), abs(a.second - b.second)};
	return sqrt(pow(tmp.first, 2.0) + pow(tmp.second, 2.0));
}

int main() {
	ll n;
	cin >> n;

	double x, y;
	vector<P> p(n);
	rep(i, n) {
		cin >> x >> y;
		p[i] = P{x, y};
	}

	double ans = 0.0;
	rep(i, n - 1) {
		for (ll j = i + 1;j < n;j++) {
			ans = max(ans, dist(p[i], p[j]));
		}
	}

	printf("%.6lf\n", ans);

	return 0;
}