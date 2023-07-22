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

bool check(set<ll> p, set<ll> q) {
	if (p.size() < q.size()) return false;
	// qの要素が全て含まれているか
	bool c = true;
	for (auto itr = q.begin();itr != q.end() && c;itr++) {
		if (p.find(*itr) == p.end()) c = false;
	}
	return c;
}

int main() {
	ll n, m;
	cin >> n >> m;

	vector<pair<ll, set<ll>>> v;
	ll c, in, p;
	rep(i, n) {
		cin >> p;
		cin >> c;
		set<ll> tmp;
		rep (j, c) {
			cin >> in;
			tmp.insert(in);
		}
		v.push_back(make_pair(p, tmp));
	}

	bool ans = false;
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			if (!(v[i].first <= v[j].first)) continue;
			if (!check(v[i].second, v[j].second)) continue;
			if (!(v[i].first < v[j].first || v[i].second.size() > v[j].second.size())) continue;
			ans = true;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}