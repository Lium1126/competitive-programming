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
	ll n, k;
	cin >> n >> k;
	ll p;
	vector<ll> under(n + 1, -1), pile(n + 1, 0);
	set<ll> board;

	vector<ll> ans(n + 1, -1);

	irep(i, n) {
		cin >> p;
		auto ub = board.upper_bound(p);
		if (ub == board.end()) {
			pile[p] = 1;
			board.insert(p);
		} else {
			under[p] = (*ub);
			pile[p] = pile[(*ub)] + 1;
			board.erase(ub);
			board.insert(p);
		}

		if (pile[p] == k) {
			board.erase(p);
			ll x = p;
			rep(j, k) {
				ans[x] = i;
				x = under[x];
			}
		}
	}

	irep(i, n) cout << ans[i] << endl;

	return 0;
}