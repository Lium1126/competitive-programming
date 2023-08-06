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
	ll n, m;
	cin >> n >> m;

	ll a, b;
	vector<bool> f(n + 1, true);
	rep(i, m) {
		cin >> a >> b;
		f[b] = false;
	}

	vector<ll> ans;
	irep(i, n) {
		if (f[i]) ans.push_back(i);
	}

	cout << (ans.size() == 1 ? ans[0] : -1) << endl;

	return 0;
}