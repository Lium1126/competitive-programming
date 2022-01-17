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

typedef pair<pair<ll, ll>, pair<ll, ll>> P;

int main() {
	ll n, m, q;
	cin >> n >> m >> q;

	ll a, b, c;
	vector<P> edge;
	rep(i, m) {
		cin >> a >> b >> c;
		edge.push_back(make_pair(make_pair(a, b), make_pair(c, -1)));
	}

	vector<short> ans(q, -1);
	rep(i, q) {
		cin >> a >> b >> c;
		edge.push_back(make_pair(make_pair(a, b), make_pair(c, i)));
	}

	sort(edge.begin(), edge.end(), [](P& a, P& b) {
		return a.second.first < b.second.first;
	});

	atcoder::dsu uf(n + 1);
	for (P x : edge) {
		ll a = x.first.first, b = x.first.second;
		ll type = x.second.second;
		if (type == -1) {
			if (!uf.same(a, b)) uf.merge(a, b);
		}
		else {
			if (!uf.same(a, b)) ans[type] = 1;
			else ans[type] = 0;
		}
	}

	rep(i, q) cout << (ans[i] == 1 ? "Yes" : "No") << endl;

	return 0;
}