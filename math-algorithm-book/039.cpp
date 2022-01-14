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
	ll n, q;
	cin >> n >> q;

	vector<ll> a(n + 2, 0);
	ll l, r, x;
	rep(i, q) {
		cin >> l >> r >> x;
		a[l] += x;
		a[r + 1] -= x;
	}

	for (ll i = 2;i <= n;i++) {
		if (a[i] > 0) cout << '<';
		else if (a[i] < 0) cout << '>';
		else cout << '=';
	}
	cout << endl;

	return 0;
}