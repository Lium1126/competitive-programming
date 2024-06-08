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
	string s;
	cin >> s;

	ll u = 0, l = 0;
	rep(i, s.length()) {
		if ('a' <= s[i] && s[i] <= 'z') l++;
		else u++;
	}

	if (u > l) {
		rep(i, s.length()) if ('a' <= s[i] && s[i] <= 'z') s[i] = 'A' + (s[i] - 'a');
	} else {
		rep(i, s.length()) if ('A' <= s[i] && s[i] <= 'Z') s[i] = 'a' + (s[i] - 'A');
	}

	cout << s << endl;

	return 0;
}