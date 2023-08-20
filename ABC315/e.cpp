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

vector<ll> ans;
vector<bool> f(200005, false);
vector<vector<ll>> v(200005);

void solve(ll i) {
	if (v[i].size() == 0) {
		if (f[i] == false) {
			ans.push_back(i);
			f[i] = true;
		}
		return;
	}
	if (f[i]) return;

	for (ll tmp : v[i]) {
		solve(tmp);
	}

	if (f[i] == false) {
		ans.push_back(i);
		f[i] = true;
	}
	return;
}

int main() {
	ll n;
	cin >> n;

	ll c, p;
	irep(i, n) {
		cin >> c;
		rep(j, c) {
			cin >> p;
			v[i].push_back(p);
		}
	}

	solve(1);
	rep(i, ans.size() - 1) {
		cout << ans[i] << ' ';
	}
	cout << endl;

	return 0;
}