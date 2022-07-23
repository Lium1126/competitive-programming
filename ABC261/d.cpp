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

int main() {
	ll n, m, ans = 0;
	cin >> n >> m;

	vector<ll> x(n + 1);
	irep(i, n) {
		cin >> x[i];
		ans += x[i];
	}
	vector<ll> bonus(n + 1, 0);
	ll c, y;
	rep(i, m) {
		cin >> c >> y;
		bonus[c] = y;
		ans += y;
	}

	vector<ll> s(n + 1, 0);
	irep(i, n) s[i] = s[i - 1] + bonus[i];
//	irep(i, n) cout << s[i] << ' '; cout << endl;

	ll last = 0;
	srep(i, 2, n - 1) {
		ll tmp = ans, num = n - i;
		tmp -= x[i];
		tmp -= (s[n - last] - s[i - last - 1]);
		tmp += s[num];
		if (ans < tmp) {
			ans = tmp;
			last = i;
		}
 	}

	cout << ans << endl;

	return 0;
}