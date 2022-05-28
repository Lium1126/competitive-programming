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
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	rep(i, 10) {
		char target = i + '0';
		vector<ll> tmp(10, 0);
		rep(j, n) {
			rep(k, s[j].length()) {
				if (target == s[j][k]) tmp[k]++;
			}
		}

/*
		cout << target << ": " << endl;
		rep(i, 10) {
			cout << i << " = " << tmp[i] << endl;
		}
*/

		ll t = 0;
		rep(i, 10) {
			if (tmp[i] == 0) continue;
			else t = max(t, 10 * (tmp[i] - 1) + i);
		}

		ans = min(ans, t);
	}

	cout << ans << endl;

	return 0;
}