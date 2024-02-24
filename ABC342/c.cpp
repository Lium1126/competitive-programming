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
	ll q;
	cin >> q;

	vector<ll> v(26);
	rep(i, 26) v[i] = i;
	char c, d;
	while (q--) {
		cin >> c >> d;
		rep(i, 26) {
			if (v[i] == (c - 'a')) v[i] = d - 'a';
		}
	}

	// rep(i, 26) {
	// 	cout << char(i + 'a') << ':' << char(v[i] + 'a') << endl;
	// }

	rep(i, s.length()) {
		cout << char(v[s[i] - 'a'] + 'a');
	}
	cout << endl;

	return 0;
}