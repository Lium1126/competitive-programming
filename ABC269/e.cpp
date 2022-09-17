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

typedef pair<ll, ll> P;

int main() {
	ll n;
	P ans = make_pair(0, 0);
	cin >> n;

	// y
	ll l = 1, u = n;
	ll c = n - 1, t;
	while (u - l > 1) {
        ll mid = (l + u) / 2;
		cout << "? " << l << ' ' << mid << ' ' << 1 << ' ' << n << endl;
		flush(cout);
		cin >> t;
		if (t == -1) return 0;
		if (t > c / 2) { u = mid, c -= (c - t); }
		else { l = mid, c -= t; }
	}

//	cout << l << ' ' << u << endl;
	ans.second = u;

	// x
	l = 1, u = n;
	c = n - 1;
	while (u - l > 1) {
        ll mid = (l + u) / 2;
		cout << "? " <<  1 << ' ' << n << ' ' << l << ' ' << mid << endl;
		flush(cout);
		cin >> t;
		if (t == -1) return 0;
		if (t > c / 2) { u = mid, c -= (c - t); }
		else { l = mid, c -= t; }
	}

	ans.first = u;

	cout << "! " << ans.first << ' ' << ans.second << endl;

	return 0;
}