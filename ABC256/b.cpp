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

	vector<ll> a(n, 0);
	rep(i, n) cin >> a[i];

	ll p = 0;
	vector<ll> v(4, 0);
	rep(i, n) {
		v[0]++;
		for (ll j = 3;j >= 0;j--) {
			if (j + a[i] >= 4) {
				p += v[j];
				v[j] = 0;
			} else {
				v[j + a[i]] += v[j];
				v[j] = 0;
			}
		}
	}
	cout << p << endl;

	return 0;
}