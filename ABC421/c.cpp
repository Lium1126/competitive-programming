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

	string s;
	cin >> s;

	vector<ll> a;
	rep(i, s.length()) {
		if (s[i] == 'A') a.push_back(i);
	}

	ll ans1 = 0, ans2 = 0;
	rep(i, a.size()) {
		ans1 += abs((i * 2) - a[i]);
	}
	rep(i, a.size()) {
		ans2 += abs((i * 2 + 1) - a[i]);
	}

	cout << min(ans1, ans2) << endl;

	return 0;
}