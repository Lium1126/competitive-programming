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
	vector<ll> a(n);
	vector<ll> v(200005, 0);
	rep(i, n) {
		cin >> a[i];
		v[a[i]]++;
	}

	ll ans = 0;
	rep(i, n) {
		for (ll j = 1;j * j <= a[i];j++) {
			if (a[i] % j == 0) {
				if (j == a[i] / j) ans += v[j] * v[a[i] / j];
				else ans += (v[j] * v[a[i] / j]) * 2;
			}
		}
	}

	cout << ans << endl;

	return 0;
}