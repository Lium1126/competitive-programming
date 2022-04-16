#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll x = 0, y = 0;
	ll inx, iny;
	rep(i, 3) {
		cin >> inx >> iny;
		x ^= inx; y ^= iny;
	}

	cout << x << ' ' << y << endl;

	return 0;
}