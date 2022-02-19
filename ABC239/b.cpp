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
	ll x;
	cin >> x;
	if (x >= 0) cout << (x / 10) << endl;
	else {
		x = -x;
		if (x % 10 != 0) cout << '-' << (x / 10) + 1 << endl;
		else cout << '-' << (x / 10) << endl;
	}
	return 0;
}