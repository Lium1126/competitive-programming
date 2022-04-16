#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, q, a;
	cin >> n;
	vector<vector<ll>> v(n + 1);
	rep(i, n) {
		cin >> a;
		v[a].push_back(i + 1);
	}
	ll l, r, x;
	cin >> q;
	rep(i, q) {
		cin >> l >> r >> x;
		if (v[x].empty()) cout << 0 << endl;
		else {
			auto itr1 = lower_bound(v[x].begin(), v[x].end(), l);
			auto itr2 = upper_bound(v[x].begin(), v[x].end(), r);
			cout << (v[x].begin() - itr1) - (v[x].begin() - itr2) << endl;
		}
	}
	return 0;
}