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
	ll n, m, sx, sy, c;
	char d;
	cin >> n >> m >> sx >> sy;
	P now = {sx, sy};
	vector<P> house(n);
	map<ll, set<ll>> x, y;
	rep(i, n) {
		cin >> house[i].first >> house[i].second;
		x[house[i].first].insert(house[i].second);
		y[house[i].second].insert(house[i].first);
	}
	ll ans = 0;
	rep(i, m) {
		P next;
		cin >> d >> c;

		if (d == 'U' || d == 'D') {
			next = P{now.first, now.second + (d == 'U' ? c : -c)};

			ll l = min(now.second, next.second);
			ll r = max(now.second, next.second);

			auto left = x[now.first].lower_bound(l);
			auto right = x[now.first].upper_bound(r);

			vector<P> rm;
			for (auto itr = left;itr != right;itr++) {
				ans++;
				rm.push_back(P{now.first, *itr});
			}

			for (P r: rm) {
				x[r.first].erase(r.second);
				y[r.second].erase(r.first);
			}
		} else {
			next = P{now.first + (d == 'R' ? c : -c), now.second};

			ll l = min(now.first, next.first);
			ll r = max(now.first, next.first);

			// cout << l << ' ' << r << endl;

			auto left = y[now.second].lower_bound(l);
			auto right = y[now.second].upper_bound(r);

			// cout << *left << ' ' << *right << ' ' << (bool)(left == right) << endl;
			vector<P> rm;
			for (auto itr = left;itr != right;itr++) {
				ans++;
				rm.push_back(P{*itr, now.second});
			}

			for (P r: rm) {
				x[r.first].erase(r.second);
				y[r.second].erase(r.first);
			}
		}

		now = next;
	}

	cout << now.first << ' ' << now.second << ' ' << ans << endl;

	return 0;
}