#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll q;
	cin >> q;
	vector<ll> a;
	ll c, x, k;
	bool f = false;
	rep(i, q) {
		cin >> c;
		if (c == 1) {
			cin >> x;
			a.push_back(x);
			f = true;
		}
		else if (c == 2) {
			cin >> x >> k;
			if(f) sort(a.begin(), a.end()), f = false;
			auto pos = lower_bound(a.begin(), a.end(), x + 1);
			if (distance(a.begin(), pos) - k >= 0) {
				cout << a[distance(a.begin(), pos) - k] << endl;
			} else cout << -1 << endl;
		} else {
			cin >> x >> k; k--;
			if(f) sort(a.begin(), a.end()), f = false;
			auto pos = lower_bound(a.begin(), a.end(), x);
			if (pos != a.end() && distance(a.begin(), pos) + k < a.size()) {
				cout << a[distance(a.begin(), pos) + k] << endl;
			} else cout << -1 << endl;
		}
	}
	return 0;
}