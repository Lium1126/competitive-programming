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

	vector<ll> a(n, __LONG_LONG_MAX__);
	ll b;
	rep(i, n - 1) {
		cin >> b;
		a[i] = min(a[i], b);
		a[i + 1] = min(a[i + 1], b);
	}

	ll sum = 0;
	rep(i, n) sum += a[i];

	cout << sum << endl;

	return 0;
}