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

	set<ll> p;
	rep(i, n) p.insert(i * i);

	rep(i, n) {
		for (ll j = i;j <= n;j++) {
			if (p.find(i * j) != p.end()) {
				ans += (i == j ? 1 : 2);
			}
		}
	}

	cout << ans << endl;

	return 0;
}