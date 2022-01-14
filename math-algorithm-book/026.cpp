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

	double ans = 0;
	for (ll i = n;i >= 1;i--) {
		ans += (double)n / (double)i;
	}

	printf("%.6lf\n", ans);

	return 0;
}