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

ll sum(ll n) {
	return n * (n + 1) / 2;
}

int main() {
	ll n, m;
	cin >> n >> m;

	vector<P> x(m);
	ll s = 0;
	rep(i, m) cin >> x[i].first;
	rep(i, m) {
		cin >> x[i].second;
		s += x[i].second;
	}

	x.push_back(P{n + 1, 0});
	sort(x.begin(), x.end());
	bool flag = (s == n && x[0].first == 1 ? true : false);
	ll ans = 0;

	rep(i, m) {
		if (x[i].first + x[i].second < x[i + 1].first) flag = false;
		else {
			ll dif = x[i + 1].first - x[i].first - 1;
			ans += sum(dif) + (x[i].second - dif - 1) * (x[i + 1].first - x[i].first);
			x[i + 1].second += (x[i].second - dif - 1);
		}
	}

	cout << (flag ? ans : -1LL) << endl;

	return 0;
}