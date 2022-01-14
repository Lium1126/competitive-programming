#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<bool> tbl(n + 1, true);
	vector<ll> ans;

	for (ll i = 2;i <= n;i++) {
		if (tbl[i]) {
			ans.push_back(i);
			for (ll j = 2 * i;j <= n;j += i) tbl[j] = false;
		}
	}

	rep(i, ans.size()) {
		cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');
	}

	return 0;
}