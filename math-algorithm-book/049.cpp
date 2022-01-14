#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (1000000007)

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
	ll n;
	cin >> n;

	if (n <= 2) cout << 1 << endl;
	else {
		mint a, b, tmp;
		a = b = 1;
		for (ll i = 3;i <= n;i++) {
			tmp = a + b;
			a = b;
			b = tmp;
		}

		cout << tmp.val() << endl;
	}

	return 0;
}