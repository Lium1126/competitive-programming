#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	double a, b;
	double d;
	cin >> a >> b >> d;

	double rad = d * M_PI / 180.0;
	double x = cos(rad) * a - sin(rad) * b;
	double y = sin(rad) * a + cos(rad) * b;

	printf("%.12lf %.12lf\n", x, y);

	return 0;
}