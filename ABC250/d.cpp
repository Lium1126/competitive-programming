#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll tmp(ll a, ll b) {
	return a * b * b * b;
}

int main() {
	ll n;
	cin >> n;

	vector<bool> pf(1000001, true);
	vector<ll> p;
	pf[0] = pf[1] = false;
	for (ll i = 2;i <= 1000000;i++) {
		if (pf[i]) {
			p.push_back(i);
			for (ll j = i * 2;j <= 1000000;j += i) pf[j] = false;
		}
	}

//	cout << p.size() << endl;
	ll ans = 0;
	rep(i, p.size()) {
		for (ll j = i + 1;j < p.size() && tmp(p[i], p[j]) <= n;j++) {
			cout << p[i] << ' ' << p[j] << ' ' << tmp(p[i], p[j]) << endl;
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}