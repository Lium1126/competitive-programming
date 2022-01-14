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

	ll a;
	map<ll, ll> mp;
	rep(i, n) {
		cin >> a;
		mp[a]++;
	}

	ll ans = 0;
	for (ll i = 1;i <= 3;i++) {
		ans += (mp[i] * (mp[i] - 1)) / 2;
	}

	cout << ans << endl;

	return 0;
}