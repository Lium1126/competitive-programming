#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, m;
	vector<pair<ll, ll>> input;
	cin >> n >> m;

	atcoder::dsu uf(n);
	rep(i, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		input.push_back(make_pair(a, b));
		uf.merge(a, b);
	}

	map<int, ll> mp;
	rep(i, m) {
		mp[uf.leader(input[i].first)]++;
	}

	bool f = true;
	for (vector<int> vec : uf.groups()) {
		if (vec.size() != mp[uf.leader(vec[0])]) f = false;
	}

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}