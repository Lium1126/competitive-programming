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

ll val(ll i, ll j) {
	if (j == 0 || j == i) return 1;
	return val(i - 1, j - 1) + val(i - 1, j);
}

int main() {
	ll n;
	cin >> n;

	rep(i, n) {
		rep(j, i + 1) {
			ll tmp = val(i, j);
			cout << tmp;
			if (j != i) cout << ' ';
		}
		cout << endl;
	}

	return 0;
}