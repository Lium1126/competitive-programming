#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<ll> c(10);
	rep(i, 9) cin >> c[i];

	string ans = "";

	ll m = __LONG_LONG_MAX__;
	rep(i, 9) m = min(m, c[i]);

	ll leng = n / m;
	for (ll i = 0;i < leng;i++) {
		for (ll j = 9;j >= 1;j--) {
			if (m * (leng - 1 - i) + c[j] <= n) {
				n -= c[j];
				ans += (char)(j + '0');
				break;
			}
		}
	}

	cout << ans << endl;

	return 0;
}