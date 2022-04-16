#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	double x, y;
	cin >> x >> y;

	double d = atan(y / x);
	double dist = sqrt(x * x + y * y);
	printf("%.12lf %.12lf\n", cos(d), sin(d));

	return 0;
}