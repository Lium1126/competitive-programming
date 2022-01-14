#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;

	ll ansc = 0;
	for (ll red = 1;red <= n;red++) {
		for (ll white = max(1LL, red - (k - 1));white <= min(n, red + (k - 1));white++) {
			for (ll blue = max(1LL, red - (k - 1));blue <= min(n, red + (k - 1));blue++) {
				if (abs(white - blue) <= k - 1) ansc++;
			}
		}
	}

	cout << n * n * n - ansc << endl;
	
	return 0;
}