#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll f(ll x) {
	return x * x + 2 * x + 3;
}

int main() {
	ll t;
	cin >> t;

	cout << (f(f(f(t) + t) + f(f(t)))) << endl;

	return 0;
}