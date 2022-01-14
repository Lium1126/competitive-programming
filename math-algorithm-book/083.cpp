#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = 0;
	rep(i, n) ans += abs(a[i] - b[i]);

	cout << ans << endl;

	return 0;
}