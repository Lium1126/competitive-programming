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
	ll n, q;
	cin >> n;

	vector<ll> v(n + 1), s(n + 1, 0), tm(n + 1, 0);
	irep(i, n) {
		cin >> v[i];
	}

	ll t, i, x, last = -1, lasttime = -1;
	cin >> q;
	rep(cnt, q) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			last = x;
			lasttime = cnt;
		}
		else if (t == 2) {
			cin >> i >> x;
			if (tm[i] < lasttime) s[i] = 0;
			s[i] += x;
			tm[i] = cnt;
		}
		else {
			cin >> i;
			if (tm[i] < lasttime) s[i] = tm[i]= 0;
			if (last == -1) {
				cout << v[i] + s[i] << endl;
			}
			else {
				cout << last + s[i] << endl;
			}
		}
	}

	return 0;
}