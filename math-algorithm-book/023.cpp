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

	double red = 0, blue = 0, r, b;
	rep(i, n) {
		cin >> r;
		red += r;
	}
	rep(i, n) {
		cin >> b;
		blue += b;
	}

	printf("%.6lf\n", (red + blue) / (double)n);

	return 0;
}