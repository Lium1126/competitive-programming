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
	ll t;
	cin >> t;

	while(t--) {
		ll n;
		cin >> n;

		vector<ll> a(2 * n);
		rep(i, 2 * n) {
			cin >> a[i];
		}

		ll ans = 0;
		set<P> s;
		rep(i, 2 * n - 1) {
			if (a[i] == a[i + 1]) {
				i++;
				continue;
			}

			if (s.find(P(min(a[i], a[i + 1]), max(a[i], a[i + 1]))) != s.end()) {
				ans++;
			} else {
				s.insert(P(min(a[i], a[i + 1]), max(a[i], a[i + 1])));
			}
		}

		cout << ans << endl;
	}

	return 0;
}