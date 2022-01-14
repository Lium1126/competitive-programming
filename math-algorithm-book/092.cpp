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
	ll n;
	cin >> n;

	ll ans = __LONG_LONG_MAX__;
	for (ll i = 1;i * i <= n;i++) {
		if (n % i == 0) {
			ll j = n / i;
			ans = min(ans, 2 * i + 2 * j);
		}
	}

	cout << ans << endl;

	return 0;
}