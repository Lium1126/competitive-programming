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
	ll n;
	cin >> n;

	vector<ll> v(n), twocnt(n), threecnt(n);
	set<ll> s;
	ll in;
	rep(i, n) {
		cin >> in;
		ll two = 0, three = 0;
		v[i] = in;
		while (in % 2 == 0) in /= 2, two++;
		while (in % 3 == 0) in /= 3, three++;
		twocnt[i] = two;
		threecnt[i] = three;
		s.insert(in);
	}

	if (s.size() != 1) {
		cout << "-1" << endl; 
	} else {
		ll twom = __LONG_LONG_MAX__, threem = __LONG_LONG_MAX__;
		rep(i, n) {
			twom = min(twom, twocnt[i]);
			threem = min(threem, threecnt[i]);
		}

		ll ans = 0;
		rep(i, n) {
			ans += twocnt[i] - twom;
			ans += threecnt[i] - threem;
		}

		cout << ans << endl;
	}

	return 0;
}