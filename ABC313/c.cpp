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

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	sort(a.begin(), a.end());
	
	ll sum = 0;
	rep(i, n) sum += a[i];
	bool m = false;
	if (sum % n == 0) m = true;
	ll avg = sum / n;

	ll ans = 0;
	if (m) {
		rep(i, n) ans += abs(a[i] - avg);
		cout << ans / 2 << endl;
	}
	else {
		rep(i, n) {
			if (a[i] > avg + 1) {
				ans += a[i] - (avg + 1);
				a[i] = avg + 1;
			}
			if (a[i] < avg) {
				ans += avg - a[i];
				a[i] = avg;
			}
		}
		ll tmp = 0;
		for (ll out : a) {
//			cout << out << ' ';
			tmp += out;
		}
//		cout << endl;
//		cout << tmp << ' ' << sum << endl;
		ans += abs(sum - tmp);
		cout << (ans + 1) / 2 << endl;
	}

	return 0;
}