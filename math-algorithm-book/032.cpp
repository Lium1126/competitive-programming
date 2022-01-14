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
	ll n, x;
	cin >> n >> x;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	sort(a.begin(), a.end());

	auto itr = lower_bound(a.begin(), a.end(), x);
	cout << (*itr == x ? "Yes" : "No") << endl;

	return 0;
}