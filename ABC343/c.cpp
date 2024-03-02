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

bool isKaibun(string s) {
	rep(i, s.length()) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

string toString(ll v) {
	string s = "";
	while (v != 0) {
		s = char((v % 10) + '0') + s;
		v /= 10;
	}
	return s;
}

int main() {
	ll n;
	cin >> n;

	ll ans = 1;
	for (ll i = 2;i * i * i <= n;i++) {
		if (isKaibun(toString(i * i * i))) ans = i * i * i;
	}

	cout << ans << endl;

	return 0;
}