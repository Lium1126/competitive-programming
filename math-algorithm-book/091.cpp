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
	ll n, x;
	cin >> n >> x;

	ll ans = 0;
	for (ll a = 1;a <= n - 2;a++) {
		for (ll b = a + 1;b <= n - 1;b++) {
			ll c = x - a - b;
			if (b < c && c <= n) ans++;
		}
	}

	cout << ans << endl;

	return 0;
}