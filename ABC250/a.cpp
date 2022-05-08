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
	ll h, w;
	cin >> h >> w;
	ll r, c;
	cin >> r >> c;
	ll ans = 4;
	if (r == 1) ans--;
	if (r == h) ans--;
	if (c == 1) ans--;
	if (c == w) ans--;
	cout << ans << endl;
	return 0;
}