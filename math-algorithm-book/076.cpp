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

	vector<ll> a(n + 1);
	rep(i, n) cin >> a[i];

	sort(a.begin() + 1, a.end());

	ll ans = 0;
	rep(i, n) ans += a[i] * (-n + 2LL * i - 1LL);

	cout << ans << endl;

	return 0;
}