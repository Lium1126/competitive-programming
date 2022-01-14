#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define srep(i, s, e) for (ll i = s;i < e;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	ll cnt = 0;
	rep(i1, n) {
		srep(i2, i1 + 1, n) {
			srep(i3, i2 + 1, n) {
				srep(i4, i3 + 1, n) {
					srep(i5, i4 + 1, n) {
						if (a[i1] + a[i2] + a[i3] + a[i4] + a[i5] == 1000) cnt++;
					}
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}