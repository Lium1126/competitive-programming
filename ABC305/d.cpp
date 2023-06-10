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
	ll n, in;
	cin >> n;
	vector<ll> v;
	rep(i, n) {
		cin >> in;
		v.push_back(in);
	}

	vector<ll> sum, night;
	for (ll i = 1;i < n;i += 2) night.push_back(v[i + 1] - v[i]);
//	for (ll out : night) cout << out << endl;
	sum.push_back(0);
	rep(i, night.size()) {
		sum.push_back(sum[sum.size() - 1] + night[i]);
	}
	// rep(i, sum.size()) {
	// 	cout << i << ": " << sum[i] << endl;
	// }

	ll q, l, r;
	cin >> q;
	while (q--) {
		ll ans = 0;
		cin >> l >> r;

		auto litr = lower_bound(v.begin(), v.end(), l) - v.begin();
		auto ritr = lower_bound(v.begin(), v.end(), r) - v.begin();
//		cout << litr << ' ' << ritr << endl;
		if (litr % 2 == 0) ans += v[litr] - l, l = v[litr];
		else l = v[litr - 1];
		if (ritr % 2 == 0) ans += r - v[ritr - 1], r = v[ritr - 1];
		else r = v[ritr];

//		cout << ans << ' ' << l << "(" << litr << ")->" << r << "(" << ritr << ")" << endl;

		ans += (sum[(ritr - 1) / 2] - sum[litr / 2]);

		cout << ans << endl;
	}

	return 0;
}