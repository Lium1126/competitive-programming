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

	vector<set<ll>> v;
	ll c;
	rep(i, n) {
		set<ll> s;
		cin >> c;
		ll a;
		rep(j, c) {
			cin >> a;
			s.insert(a);
		}
		v.push_back(s);
	}

	ll x;
	cin >> x;

	ll size = __LONG_LONG_MAX__;
	vector<P> ans;
	rep(i, n) {
		if (v[i].find(x) != v[i].end()) {
			size = min(size, (ll)(v[i].size()));
			ans.push_back(P{i + 1, v[i].size()});
		}
	}

	vector<ll> a;
	for (P elem : ans) {
		if (size == elem.second) a.push_back(elem.first);
	}

	cout << a.size() << endl;
	for (ll out : a) cout << out << ' ';
	cout << endl;

	return 0;
}