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

	vector<ll> x(n + 1), y(n + 1);
	rep(i, n) cin >> x[i] >> y[i];

	sort(x.begin() + 1, x.end());
	sort(y.begin() + 1, y.end());

	ll ans = 0;
	rep(i, n) {
		ans += x[i] * (-n + 2LL * i - 1LL);
		ans += y[i] * (-n + 2LL * i - 1LL);
	}

	cout << ans << endl;

	return 0;
}