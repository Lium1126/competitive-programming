#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	vector<ll> a(n);
	set<ll> s;
	rep(i, n) {
		cin >> a[i];
		s.insert(a[i]);
	}

	sort(a.begin(), a.end());

	ll cnt = 0;
	vector<ll> k(n, 0);
	rep(i, n) {
		if (i == 0) continue;
		if (a[i] != a[i - 1]) cnt++;
		k[i] = cnt;
	}

/*
	rep(i, n) cout << k[i] << ' ';
	cout << endl;
*/

	rep(i, n) {
		if (k[i] == 0 || k[i] == s.size() - 1) continue;
		ll r = lower_bound(k.begin(), k.end(), k[i] + 1) - k.begin();
		ll l = lower_bound(k.begin(), k.end(), k[i]) - k.begin();
//		cout << "ans += " << l << "*" << (n - r) << endl;
		ans += (l * (n - r));
	}

	cout << ans << endl;

	return 0;
}