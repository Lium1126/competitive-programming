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
	set<ll> as, bs;
	rep(i, n) cin >> a[i];
	rep(i, n) {
		cin >> b[i];
		bs.insert(b[i]);
	}
	ll ans1 = 0, ans2 = 0;
	rep(i, n) {
		if (a[i] == b[i]) ans1++;
		else if (bs.find(a[i]) != bs.end()) ans2++;
	}

	cout << ans1 << endl << ans2 << endl;

	return 0;
}