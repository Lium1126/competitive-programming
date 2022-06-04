#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	ll ans = 0;

	rep(i, n) {
		set<ll> r;
		
		for (ll j = 1;j * j <= i;j++) {
			if (i % j == 0) {
				r.insert(j); r.insert(i / j);
			}
		}

		ll target = i * i;
		ll size = r.size(), cnt = 0;
		for (auto itr = r.begin();itr != r.end();itr++) {
			ll t = *itr;
			if (cnt == size - 1) {
				ans++;
			} else {
				if (target / t <= n && t <= n) ans += 2;
			}
			cnt++;
		}
	}

	cout << ans << endl;

	return 0;
}