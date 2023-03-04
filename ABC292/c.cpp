#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

ll f(ll a) {
	ll rec = 0;
	for (ll i = 1; i * i <= a;i++) {
		if (a % i == 0) {
			if (a / i == i) rec++;
			else rec += 2;
		}
	}
	return rec;
}

int main() {
	ll n;
	ll ans = 0;
	cin >> n;

	irep(i, n) {
		// iとn-iに分ける
		ll a = i, b = n - i;

		ll aans = f(a);
		ll bans = f(b);

		ans += aans * bans;
	}
	cout << ans << endl;

	return 0;
}