#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;

	ll dist = abs(x) + abs(y);

	cout <<  (dist <= n && (n & 1) == (dist & 1) ? "Yes" : "No") << endl;

	return 0;
}