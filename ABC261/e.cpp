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

int main() {
	ll n, c;
	cin >> n >> c;

	vector<ll> v(n + 1);
	vector<P> com;
	ll t, a;
	com.push_back(make_pair(t, a));
	irep(i, n) {
		cin >> t >> a;
		if (i == 1) {
			if (t == 1) v[0] = 1;
			else v[0] = 0;
		}
		if (t == 1) v[i] = v[i - 1] & a;
		if (t == 2) v[i] = v[i - 1] | a;
		if (t == 3) v[i] = v[i - 1] ^ a;
	}

	vector<ll> ans(n + 1);
	if (com[0].first == 1) ans[1] = c & com[0].second;
	if (com[0].first == 2) ans[1] = c | com[0].second;
	if (com[0].first == 3) ans[1] = c ^ com[0].second;

	srep(i, 2, n) {
		if (com[0].first == 1) ans[i] = ans[i - 1] & v[i];
		if (com[0].first == 2) ans[i] = ans[i - 1] | v[i];
		if (com[0].first == 3) ans[i] = ans[i - 1] ^ v[i];
	}

	irep(i, n) cout << ans[i] << endl;

	return 0;
}