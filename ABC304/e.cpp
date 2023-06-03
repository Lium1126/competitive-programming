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

ll power(ll a) {
	return a * a;
}

int main() {
	ll n, m;
	cin >> n >> m;

	vector<set<ll>> g(n);
	ll u, v;
	dsu uf(n);
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		uf.merge(u, v);
	}

	set<ll> parents;
	rep(i, n) {
		parents.insert(uf.leader(i));
	}
	map<ll, ll> mp;
	ll cnt = 0;
	for (auto itr = parents.begin();itr != parents.end();itr++) {
		mp[*itr] = cnt;
		cnt++;
	}
//	cout << "size = " << parents.size() << endl;
	vector<set<ll>> parents_graph(parents.size());
	ll k;
	cin >> k;
	ll x, y;
	rep(i, k) {
		cin >> x >> y;
		x--; y--;
		ll x_p = uf.leader(x);
		ll y_p = uf.leader(y);
//		cout << x_p << "(" << mp[x_p] << ") " << y_p << "(" << mp[y_p] << ")" << endl;
		parents_graph[mp[x_p]].insert(mp[y_p]);
		parents_graph[mp[y_p]].insert(mp[x_p]);
	}
/*
	rep(i, parents.size()) {
		cout << i << ": ";
		for (auto itr = parents_graph[i].begin();itr != parents_graph[i].end();itr++) {
			cout << *itr << ' ';
		}
		cout << endl;
	}
*/

	ll Q;
	cin >> Q;
	ll p, q;
	rep(cnt, Q) {
		cin >> p >> q;
		p--; q--;
		ll p_p = uf.leader(p);
		ll q_p = uf.leader(q);
		if (parents_graph[mp[p_p]].find(mp[q_p]) != parents_graph[mp[p_p]].end()) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}

	return 0;
}