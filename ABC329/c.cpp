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

	vector<pair<char, ll>> ret;
    for (ll l = 0; l < s.length();) {
        ll r = l + 1;
        for (; r < s.length() && s[l] == s[r]; r++);
        ret.push_back({s[l], r - l});
        l = r;
    }

	map<char, ll> mp;
	for (pair<char, ll> p : ret) {
		// cout << p.first << ' ' << p.second << endl;
		mp[p.first] = max(mp[p.first], p.second);
	}

	ll ans = 0;
	for (pair<char, ll> m : mp) {
		ans += m.second;
	}

	cout << ans << endl;

	return 0;
}