#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = 0;
	while (a < b) {
		ans++;
		a *= c;
	}
	cout << ans << endl;
	return 0;
}