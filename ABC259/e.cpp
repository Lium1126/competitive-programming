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
	ll n, m, p, e;
	cin >> n;

	vector<map<ll, ll>> vec(n);
	vector<map<ll, ll>> mp(2);
	rep(i, n) {
		cin >> m;
		rep(j, m) {
			cin >> p >> e;
			vec[i][p] = e;
			if (mp[0][p] <= e) mp[0][p] = e;
			else if (mp[1][p] <= e) mp[1][p] = e;
		}
	}

	rep(i, 2) {
		for (auto itr = mp[i].begin();itr != mp[i].end();itr++) {
			cout << (*itr).first << ' ' << (*itr).second << endl;
		}
	}

	ll ans = 0, fans = 0;
	rep(i, n) {
		bool flag = true;
		for (auto itr = vec[i].begin();itr != vec[i].end();itr++) {
			if (mp[1][(*itr).first] < (*itr).second) flag = false;
		}
		if (flag) fans++;
		else ans++;
	}

	if (fans > 0) ans++;
	
	cout << ans << endl;

	return 0;
}