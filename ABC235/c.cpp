#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n, q;
	cin >> n >> q;

	map<ll, vector<ll>> mp;
	ll a;
	rep (i, n) {
		cin >> a;
		mp[a].push_back(i + 1);
	}

	ll x, k;
	rep(i, q) {
		cin >> x >> k;
		if (mp[x].size() < k) cout << -1 << endl;
		else cout << mp[x][k - 1] << endl;
	}

	return 0;
}