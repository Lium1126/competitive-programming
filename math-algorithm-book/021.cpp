#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll c(ll n, ll r) {
	if (r == 0 || n == r) return 1;
	return c(n - 1, r - 1) + c(n - 1, r);
}

int main() {
	ll n, r;
	cin >> n >> r;

	cout << c(n, r) << endl;

	return 0;
}