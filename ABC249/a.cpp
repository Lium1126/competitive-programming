#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

int main() {
	ll a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	ll A = 0, B = 0;
	rep(i, x) {
		if (i % (a + c) <= a && i % (a + c) != 0) A += b;
		if (i % (d + f) <= d && i % (d + f) != 0) B += e;
	}
	if (A == B) cout << "Draw" << endl;
	else cout << (A > B ? "Takahashi" : "Aoki") << endl;
	return 0;
}