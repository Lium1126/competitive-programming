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

ll f(string s) {
	ll ret = 0;
	reverse(s.begin(), s.end());
	for (char c : s) {
		ret = ret * 10 + (c - '0');
	}
	return ret;
}

string num_to_str(ll n) {
	string ret;
	while (n > 0) {
		ret += (n % 10) + '0';
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ll x, y;
	cin >> x >> y;

	vector<ll> v(11);
	v[1] = x;
	v[2] = y;

	for (ll i = 3;i <= 10;i++) {
		v[i] = f(num_to_str(v[i - 1] + v[i - 2]));
	}

	cout << v[10] << endl;

	return 0;
}