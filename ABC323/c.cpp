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
	ll n, m;
	cin >> n >> m;

	vector<P> a(m);
	rep(i, m) {
		a[i].second = i;
		cin >> a[i].first;
	}

	vector<string> s(n);
	vector<ll> p(n, 0);
	rep(i, n) {
		cin >> s[i];
		for (ll j = 0;j < m;j++) {
			if (s[i][j] == 'o') p[i] += a[j].first;
		}
		p[i] += (i + 1);
	}

	// rep(i, n) cout << p[i] << endl;

	ll maxim = -1;
	for (ll tmp : p) maxim = max(maxim, tmp);

	sort(a.begin(), a.end(), greater<P>());
	// for (P p : a) cout << p.first << ' ' << p.second << endl;

	rep(j, n) {
		if (maxim == p[j]) {
			cout << 0 << endl;
			continue;
		}

		ll diff = maxim - p[j];
		// cout << cnt << ' ' << diff << endl;

		ll tmp = 0, ans = 0, cnt = 0;
		while (tmp < diff) {
			if (s[j][a[cnt].second] == 'o') {
				cnt++;
				continue;
			}
			ans++;
			tmp += a[cnt].first;
			cnt++;
		}
		cout << ans << endl;
	}

	return 0;
}