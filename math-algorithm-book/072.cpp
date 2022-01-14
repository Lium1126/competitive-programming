#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll a, b;

bool check(ll t) {
	ll r = b / t;
	ll l = (a + t - 1) / t;
	return (r - l >= 1 ? true : false);
}

int main() {
	cin >> a >> b;

	ll ans = 0;
	for (ll i = 1;i <= b;i++) {
		if (check(i)) ans = i;
	}

	cout << ans << endl;

	return 0;
}