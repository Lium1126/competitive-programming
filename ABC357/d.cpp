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
#define MOD (998244353)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

ll to_num(string s) {
	ll tmp = 0;
	rep(i, s.length()) {
		tmp *= 10;
		tmp += s[i] - '0';
	}
	return tmp;
}

ll power(ll n, ll x) {
	if (x == 0) return 1;
	if (x == 1) return n % MOD;
	if (x % 2 == 0) return power(((n % MOD) * (n % MOD)) % MOD, x / 2);
	else return ((power(((n % MOD) * (n % MOD)) % MOD, x / 2) % MOD) * (n % MOD));
}

int main() {
	string s;
	cin >> s;

	ll l = s.length();
	ll n = to_num(s);
	// cout << n << ' ' << l << endl;

	ll ans = n % MOD;
	for (ll i = 1;i < n;i++) {
		ans = (ans % MOD + (((n % MOD) * (power(10, l * i) % MOD)) % MOD)) % MOD;
	}

	cout << ans << endl;

	return 0;
}