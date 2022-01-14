#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll ncr(ll n, ll r) {
	if (n < 3 && r < 3) {
		if (n < r) return 0;
		return (n == 2 && r == 1 ? n : 1);
	}
	return (ncr(n / 3, r / 3) * ncr(n % 3, r % 3)) % 3;
}

int main() {
	ll n;
	cin >> n;

	string s;
	cin >> s;

	map<char, ll> mp;
	mp['B'] = 0; mp['W'] = 1; mp['R'] = 2;

	ll ans = 0;
	rep(i, n) {
		ans += mp[s[i]] * ncr(n - 1, i);
		ans %= 3;
	}

	if (!(n & 1)) ans = (6 - ans) % 3;

	string anstr = "BWR";
	cout << anstr[ans] << endl;

	return 0;
}