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
	ll n, k;
	ll m = 0;
	cin >> n >> k;

	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		m = max(a[i], m);
	}

	ll in;
	set<ll> b;
	rep(i, k) {
		cin >> in;
		in--;
		b.insert(in);
	}

	bool f = false;
	rep(i, n) {
		if (a[i] == m && b.find(i) != b.end()) f = true;
	}

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}