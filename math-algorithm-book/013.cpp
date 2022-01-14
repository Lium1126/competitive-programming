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

	for (ll i = 1;i * i <= n;i++) {
		if (n % i == 0) {
			cout << i << endl;
			if (n / i != i) cout << n / i << endl;
		}
	}

	return 0;
}