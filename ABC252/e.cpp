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

class P {
public:
	ll id;
	ll from;
	ll to;
	ll cost;


	// コストの大小で順序定義
	bool operator<(const P& o) const {
	    if (cost != o.cost) return cost < o.cost;
		return id < o.id;
	}
};

int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> ans;
	vector<P> g;

	ll a, b, c;
	rep(i, m) {
		cin >> a >> b >> c;
		P p; p.id = i; p.from = a - 1; p.to = b - 1; p.cost = c;
		g.push_back(p);
	}

	sort(g.begin(), g.end());

	atcoder::dsu uf(n);
	rep(i, m) {
		P target = g[i];
		if (!uf.same(target.from, target.to)) {
			uf.merge(target.from, target.to);
			ans.push_back(target.id);
		}
	}

	rep(i, ans.size()) cout << ans[i] + 1 << (i != ans.size() - 1 ? ' ' : '\n');

	return 0;
}