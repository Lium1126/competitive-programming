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

int main() {
	ll h, w, q, r, c;
	cin >> h >> w >> q;

	vector<set<ll>> mp(h + 1);
	vector<set<ll>> mt(w + 1);

	irep(i, h) irep(j, w) mp[i].insert(j);
	irep(i, w) irep(j, h) mt[i].insert(j);

	while(q--) {
		cin >> r >> c;

		if (mp[r].find(c) != mp[r].end()) {
			// 壁がある
			mp[r].erase(c);
			mt[c].erase(r);
		}
		else {
			// 壁がない
			set<P> v;

			if (mp[r].size() == 1) v.insert(P{r, *(mp[r].begin())});
			else if (mp[r].size() > 0) {
				auto itr = mp[r].upper_bound(c);
				if (itr == mp[r].end()) {
					itr--;
					v.insert(P{r, *itr});
				}
				else if (itr == mp[r].begin()) v.insert(P{r, *itr});
				else {
					v.insert(P{r, *itr});
					itr--;
					v.insert(P{r, *itr});
				}
			}

			if (mt[c].size() == 1) v.insert(P{*(mt[c].begin()), c});
			else if (mt[c].size() > 0) {
				auto itr = mt[c].upper_bound(r);
				if (itr == mt[c].end()) {
					itr--;
					v.insert(P{*itr, c});
				}
				else if (itr == mt[c].begin()) v.insert(P{*itr, c});
				else {
					v.insert(P{*itr, c});
					itr--;
					v.insert(P{*itr, c});
				}
			}

			// cout << "---" << endl;
			for (P p : v) {
				// cout << p.first << ' ' << p.second << endl;
				mp[p.first].erase(p.second);
				mt[p.second].erase(p.first);
			}
			// cout << "---" << endl;
		}

		// cout << "==============================" << endl;
		// irep(i, h) {
		// 	for (auto itr = mp[i].begin();itr != mp[i].end();itr++) cout << *itr << ' ';
		// 	cout << endl;
		// }
		// cout << "==============================" << endl;
		// irep(i, w) {
		// 	for (auto itr = mt[i].begin();itr != mt[i].end();itr++) cout << *itr << ' ';
		// 	cout << endl;
		// }
		// cout << "==============================" << endl;
	}

	ll ans = 0;
	irep(i, h) {
		ans += mp[i].size();
	}
	cout << ans << endl;

	return 0;
}