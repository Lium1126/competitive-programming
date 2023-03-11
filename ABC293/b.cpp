#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<bool> called(n, false);
	ll a;
	rep(i, n) {
		cin >> a;
		a--;
		if (!called[i]) called[a] = true;
	}

	vector<ll> ans;
	rep(i, n) if (!called[i]) ans.push_back(i + 1);
	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << ' ';
	cout << endl;

	return 0;
}