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
	ll n, m, u, v;
	cin >> n >> m;

	vector<set<ll>> from(n), to(n);
	rep(i, m) {
		cin >> u >> v;
		u--; v--;
		to[u].insert(v);
		from[v].insert(u);
	}
	ll ans = 0;

	rep(i, n) {
		for (auto from_itr = from[i].begin();from_itr != from[i].end();from_itr++) {
			for (auto to_itr = to[i].begin();to_itr != to[i].end();to_itr++) {
				if (to[*from_itr].find(*to_itr) == to[*from_itr].end()) {
					ans++;
					cout << *from_itr+1 << " -> (" << i+1 << ") -> " << *to_itr+1 << endl;
					to[*from_itr].insert(*to_itr);
					from[*to_itr].insert(*from_itr);
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}