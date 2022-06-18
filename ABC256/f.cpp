#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
#define mint atcoder::modint998244353

int main() {
	ll n, q;
	cin >> n >> q;

	vector<mint> a(n);
	ll in;
	rep(i, n) {
		cin >> in;
		a[i] = in;
	}

	ll t, x, v;
	rep(cnt, q) {
		cin >> t;
		if (t == 1) {
			cin >> x >> v;
			a[x - 1] = v;
		} else {
			cin >> x;
			mint ans = 0;
			rep(i, x) {
				ll r = x - i;
				mint k = (r * (r + 1)) / 2;
				ans += k * a[i];
			}
			cout << ans.val() << endl;
		}
	}

	return 0;
}