#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
vector<ll> ans;

void solve(ll n) {
	if (n == 1) {
		ans.push_back(1);
		return;
	}
	solve(n - 1);
	ans.push_back(n);
	solve(n - 1);
	return;
}

int main() {
	ll n;
	cin >> n;
	solve(n);
	rep(i, ans.size()) {
		cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}