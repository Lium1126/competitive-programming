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
	ll t, n;
	cin >> t >> n;

	vector<ll> a(t + 2, 0);
	ll l, r;
	rep(i, n) {
		cin >> l >> r;
		a[l + 1] += 1;
		a[r + 1] -= 1;
	}

	vector<ll> b(t + 2, 0);
	for (ll i = 1;i <= t + 1;i++) b[i] = b[i - 1] + a[i];

	for (ll i = 1;i <= t;i++) cout << b[i] << endl;

	return 0;
}