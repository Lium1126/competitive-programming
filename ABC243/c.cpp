#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n, x, y;
	cin >> n;
	vector<P> v;
	rep(i, n) {
		cin >> x >> y;
		v.push_back(P{x, y});
	}
	string s;
	cin >> s;

	map<ll, P> m;
	rep(i, n) {
		if (m[v[i].second].first == 0 && m[v[i].second].second == 0) m[v[i].second].first = __LONG_LONG_MAX__;
		if (s[i] == 'R') m[v[i].second].first = min(v[i].first, m[v[i].second].first);
		else m[v[i].second].second = max(v[i].first, m[v[i].second].second);
	}

	bool flag = false;
	for (pair<ll, P> x : m) {
//		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
		if (x.second.first < x.second.second) flag = true;
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}