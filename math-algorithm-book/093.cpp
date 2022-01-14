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
	ll a, b;
	cin >> a >> b;

	if (a > b) swap(a, b);

	ll g = gcd(a, b);

	if (a / g > 1000000000000000000 / b) cout << "Large" << endl;
	else cout << a / g * b << endl;

	return 0;
}