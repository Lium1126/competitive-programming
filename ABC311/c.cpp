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
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
	}

	vector<bool> visited(n, false);
	ll now = 0;
	while (visited[now] == false) {
		visited[now] = true;
		now = a[now];
	}

	// cout << now << endl;

	ll start = now;
	vector<ll> ans;
	ans.push_back(now);
	now = a[now];
	while (now != start) {
		ans.push_back(now);
		now = a[now];
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] + 1 << ' ';
	cout << endl;

	return 0;
}