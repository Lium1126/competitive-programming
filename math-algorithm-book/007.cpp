#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;

	if (x != y)	cout << (n / x) + (n / y) - (n / lcm(x, y)) << endl;
	else cout << n / x << endl;

	return 0;
}