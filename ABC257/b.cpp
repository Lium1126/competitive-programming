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
	ll n, k, q, l;
	cin >> n >> k >> q;

	vector<ll> a(k);
	rep(i, k) cin >> a[i];

	rep(cnt, q) {
		cin >> l;
		l--;
		if (a[l] == n) continue;
		else if (l == k - 1) a[l]++;
		else if (a[l + 1] == a[l] + 1) continue;
		else a[l]++;
//		cout << cnt << ";";
//		rep(i, k) cout << a[i] << (i != k - 1 ? ' ' : '\n');
	}

	rep(i, k) cout << a[i] << (i != k - 1 ? ' ' : '\n');

	return 0;
}