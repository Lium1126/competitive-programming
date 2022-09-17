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

typedef pair<ll,ll> P;

bool isNeighbor(P a, P b) {
	P d[6] = {
		P{-1, -1},
		P{-1, 0},
		P{0, -1},
		P{0, 1},
		P{1, 0},
		P{1, 1}
	};
	rep(i, 6) {
		P tmp = make_pair(b.first + d[i].first, b.second + d[i].second);
		if (a == tmp) return true;
	}
	return false;
}

int main() {
	ll n, x, y;
	cin >> n;
	vector<P> v(n);

	atcoder::dsu uf(n);
	rep(i, n) {
		cin >> x >> y;
		v[i].first = x, v[i].second = y;
	}

	sort(v.begin(), v.end());

	rep(i, n) {
		srep(j, i + 1, n - 1) {
			if (isNeighbor(v[i], v[j])) uf.merge(i, j);
		}
	}

	cout << uf.groups().size() << endl;

	return 0;
}