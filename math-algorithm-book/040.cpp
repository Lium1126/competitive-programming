#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n, 0);
	ll input;
	for (ll i = 1;i <= n - 1;i++) {
		cin >> input;
		a[i] = a[i - 1] + input;
	}

	ll m;
	cin >> m;

	ll now, to, ans = 0;
	cin >> now;

	rep(i, m - 1) {
		cin >> to;

		ll mn = min(now, to), mx = max(now, to);
//		cout << now << "->" << to << ": " << a[mx - 1] - a[mn - 1] << endl;
		ans += a[mx - 1] - a[mn - 1];

		now = to;
	}

	cout << ans << endl;

	return 0;
}