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

ll decfrombin(string s) {
	ll sum = 0;
	ll tmp = 1;
	rrep(i, s.length()) {
		if (s[i] == '1') sum += tmp;
		tmp <<= 1;
	}
	return sum;
}

int main() {
	string s, ss;
	ll n;

	cin >> s >> n;

	ll ans = decfrombin(s);
	if (ans > n) {
		cout << -1 << endl;
		return 0;
	}

	rep(i, s.length()) {
		if (s[i] == '?') {
			string ss = s;
			ss[i] = '1';
			ll tmp = decfrombin(ss);
			if (tmp > ans && tmp <= n) {
				ans = tmp;
				s = ss;
			}
		}
	}

	cout << ans << endl;

	return 0;
}