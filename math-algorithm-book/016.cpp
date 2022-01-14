#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll mygcd(ll a, ll b) {
	if (a == 0) return b;
	if (b == 0) return a;

	if (a > b) return mygcd(a % b, b);
	else return mygcd(a, b % a);
}

int main() {
	ll n, ans, a, b;
	cin >> n;

	cin >> a >> b;
	ans = mygcd(a, b);

	rep(i, n - 2) {
		cin >> a;
		ans = mygcd(ans, a);
	}

	cout << ans << endl;

	return 0;
}