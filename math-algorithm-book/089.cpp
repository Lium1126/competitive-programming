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
	ll a, b, c;
	cin >> a >> b >> c;

	if (c == 1) cout << "No" << endl;
	else {
		ll p = 1;
		rep(i, b) {
			if (a / c < p) {
				cout << "Yes" << endl;
				return 0;
			}
			p *= c;
		}

		cout << "No" << endl;
	}

	return 0;
}