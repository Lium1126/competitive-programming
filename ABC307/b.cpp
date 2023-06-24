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

bool is(string s) {
	bool rec = true;
	rep(i, s.length() / 2) {
		if (s[i] != s[s.length() - 1 - i]) rec = false;
	}
	return rec;
}

int main() {
	bool ans = false;
	ll n;
	cin >> n;

	vector<string> v(n);
	rep(i, n) cin >> v[i];

	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			string s = v[i] + v[j];
			ans |= is(s);
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}