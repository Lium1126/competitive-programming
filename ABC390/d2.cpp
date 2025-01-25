#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

set<ll> s;

vector<vector<ll>> generateGroup(vector<ll> a, ll k) {
	vector<vector<ll>> res;
	vector<ll> tmp;
	rep(i, a.size()) {
		tmp.push_back(a[i]);
		if (tmp.size() == k) {
			res.push_back(tmp);
			tmp.clear();
		}
	}
	if (tmp.size() != 0) res.push_back(tmp);
	return res;
}

ll fullXOR(vector<ll> a) {
	ll res = 0;
	rep(i, a.size()) {
		res ^= a[i];
	}
	return res;
}

ll fullSum(vector<ll> a) {
	ll res = 0;
	rep(i, a.size()) {
		res += a[i];
	}
	return res;
}

ll solve(vector<vector<ll>> group) {
	vector<ll> tmp;
	for (vector<ll> g : group) {
		tmp.push_back(fullSum(g));
	}

	return fullXOR(tmp);
}

int main() {
	ll n;
	cin >> n;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	s.insert(fullXOR(a));

	do {
		vector<ll> b = a;

		// bをK個のグループに分割した時の全てを列挙
		vector<vector<vector<ll>>> groups;
		rep(k, n) {
			vector<vector<ll>> group = generateGroup(b, k);
			if (group.size() == 0) break;
			groups.push_back(group);
		}

		for (vector<vector<ll>> group : groups) {
			s.insert(solve(group));
		}
	} while (next_permutation(a.begin(), a.end()));

	cout << s.size() << endl;

	return 0;
}