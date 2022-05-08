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
	ll n;
	cin >> n;

	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	ll q, x, y;
	cin >> q;
	rep(i, q) {
		cin >> x >> y;
		set<ll> A, B;
		rep(i, x) A.insert(a[i]);
		rep(i, y) B.insert(b[i]);
		cout << (A == B ? "Yes" : "No") << endl;
	}

	return 0;
}