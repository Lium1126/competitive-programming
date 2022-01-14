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
	ll n, ans, a, b;
	cin >> n;

	cin >> a >> b;
	ans = lcm(a, b);

	rep(i, n - 2) {
		cin >> a;
		ans = lcm(ans, a);
	}

	cout << ans << endl;

	return 0;
}