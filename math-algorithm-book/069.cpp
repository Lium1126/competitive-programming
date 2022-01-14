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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	cout << max(max(a * c, a * d), max(b * c, b * d)) << endl;

	return 0;
}