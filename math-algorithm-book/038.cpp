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

	ll a;
	vector<ll> b(n + 1, 0);
	for (ll i = 1;i <= n;i++) {
		cin >> a;
		b[i] = b[i - 1] + a;
	}

	ll l, r;
	rep(i, q) {
		cin >> l >> r;
		cout << b[r] - b[l - 1] << endl;
	}

	return 0;
}