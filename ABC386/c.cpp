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
	ll k; cin >> k;
	string s, t; cin >> s >> t;

	if (abs((ll)(s.length() - t.length())) >= 2) {
		cout << "No" << endl;
		return 0;
	}

	if (s.length() == t.length()) {
		ll cnt = 0;
		rep(i, s.length()) {
			if (s[i] != t[i]) cnt++;
		}
		if (cnt <= 1) {
			cout << "Yes" << endl;
			return 0;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}

	if (s.length() < t.length()) swap(s, t);

	bool skipped = false;
	size_t i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		} else if (!skipped) {
			i++;
			skipped = true;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}