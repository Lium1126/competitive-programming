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

	cout << (c - a - b >= 0 && 4 * a * b < (c - a - b) * (c - a - b) ? "Yes" : "No") << endl;

	return 0;
}