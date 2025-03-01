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

	ll in;
	map<ll, vector<ll>> m;
	bool flag = false;
	rep(i, n) {
		cin >> in;
		if (m[in].size() != 0) flag = true;
		m[in].push_back(i);
	}

	if (!flag) {
		cout << -1 << endl;
		return 0;
	}

	ll ans = __LONG_LONG_MAX__;
	for (auto elem: m) {
		for (ll i = 0;i < elem.second.size() - 1;i++) {
			ans = min(ans, elem.second[i + 1] - elem.second[i] + 1);
		}
	}

	cout << ans << endl;

	return 0;
}