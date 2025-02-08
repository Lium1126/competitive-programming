#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
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
typedef pair<ll, P> PP;

int main() {
	ll n, m;
	cin >> n >> m;

	ll a, b;
	atcoder::dsu d(n);
	vector<P> edge(m);
	vector<ll> extra;
	rep(i, m) {
		cin >> a >> b;
		if (d.same(a - 1, b - 1))
			extra.emplace_back(i);
		d.merge(a - 1, b - 1);
		edge[i] = {a - 1, b - 1};
	}

	map<ll, vector<ll>> nodes;
	rep(i, n) nodes[d.leader(i)].emplace_back(i);
	ll k = nodes.size();

	vector<tuple<ll, ll, ll>> ans;
	for (ll cable: extra) {
		bool flag = false;
		for (auto elem: nodes) {
			if (!d.same(edge[cable].first, elem.first)) {
				ans.emplace_back(cable, edge[cable].first, elem.first);
				d.merge(edge[cable].first, elem.first);
				flag = true;
				break;
			}
		}
		if (flag) continue;
	}

	cout << ans.size() << endl;
	for (auto elem: ans) {
		cout << get<0>(elem) + 1 << " " << get<1>(elem) + 1 << " " << get<2>(elem) + 1 << endl;
	}

	return 0;
}