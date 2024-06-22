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
	vector<ll> h(n + 1);
	vector<ll> ans(n + 1);
	map<ll, ll> idx;
	set<ll> checked;
	vector<ll> sum(n + 1, 0);
	checked.insert(__LONG_LONG_MAX__);
	idx[__LONG_LONG_MAX__] = 0;
	irep(i, n) {
		cin >> h[i];
		sum[i] = sum[i - 1] + h[i];

		auto itr = checked.lower_bound(h[i]);
		ll tmp = idx[*itr];
		ans[i] = (h[i]) * (i - tmp) - (sum[i - 1] - sum[tmp]) + ans[tmp] + 1;
		cout << tmp << ' ';

		checked.insert(h[i]);
		idx[h[i]] = i;
	}
	cout << endl;

	irep(i, n) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	
	return 0;
}