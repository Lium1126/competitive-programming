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

template<class Tree>
inline void MergeOptimized(Tree& dst, Tree& src)
{
    auto pos = dst.begin();
    while (!src.empty()) {
        auto node = src.extract(src.begin());
        pos = dst.insert(pos, std::move(node));
        ++pos;
    }
}

int main() {
	ll n, q;
	cin >> n >> q;

	vector<set<ll>> v(n + 1);
	ll in;
	irep(i, n) {
		cin >> in;
		v[i].insert(in);
	}

	ll a, b;
	set<ll> emp;
	vector<ll> ans;
	while (q--) {
		cin >> a >> b;

		MergeOptimized(v[b], v[a]);

		ans.push_back(v[b].size());
	}

	for (ll out : ans) cout << out << endl;

	return 0;
}