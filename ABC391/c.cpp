#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n + 1);
	vector<set<ll>> s(n + 1);
	irep(i, n) {
		a[i] = i;
		s[i].insert(i);
	}

	ll q;
	cin >> q;

	ll cmd, p, h;
	ll ans = 0;
	while (q--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> p >> h;

			ll cnt = s[a[p]].size();
			s[a[p]].erase(p);
			if (cnt >= 2 && s[a[p]].size() < 2) ans--;

			cnt = s[h].size();
			a[p] = h;
			s[h].insert(p);
			if (cnt < 2 && s[h].size() >= 2) ans++;

			// irep(i, n) cout << i << ": " << s[i].size() << endl;
		}
		else {
			cout << ans << endl;
		}
	}

	return 0;
}