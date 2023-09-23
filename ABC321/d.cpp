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
	ll n, m, p;
	cin >> n >> m >> p;

	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];

	sort(b.begin(), b.end());

	// rep(i, n) cout << a[i] << ' ';
	// cout << endl;
	// rep(i, m) cout << b[i] << ' ';
	// cout << endl;


	vector<ll> s(m + 1, 0);
	irep(i, m) s[i] = s[i - 1] + b[i - 1];
	// irep(i, m) cout << s[i] << ' ';
	// cout << endl;


	ll ans = 0;
	rep(i, n) {
		if (a[i] >= p) {
			ans += p * m;
		} else {
			ll border = p - a[i];
			auto itr = lower_bound(b.begin(), b.end(), border);
			ll tmp = itr - b.begin();
			// cout << a[i] << ' ' << tmp << endl;;
			ans += (s[tmp] + a[i] * tmp) + (p * (m - tmp));
		}
	}

	cout << ans << endl;

	return 0;
}

/*
5 7 11
6 1 2 4 8
3 5 8 6 9 4 1
*/