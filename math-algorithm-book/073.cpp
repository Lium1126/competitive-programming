#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
	ll n;
	cin >> n;

	vector<mint> a(n);
	ll input;
	rep(i, n) {
		cin >> input;
		a[i] = input;
	}

	mint ans = 0;
	mint c = 1;
	rep(i, n) {
		ans += c * a[i];
		c *= 2;
	}

	cout << ans.val() << endl;

	return 0;
}