#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	double h;
	cin >> h;
	printf("%.6lf\n", sqrt(h * (12800000 + h)));
	return 0;
}