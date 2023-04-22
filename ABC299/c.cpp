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
	string s;
	cin >> n;
	cin >> s;

	vector<P> v;
	for (ll l = 0;l < n;) {
		if (s[l] == 'o') {
			int r = l + 1;
			for (;r < n && s[l] == s[r];r++);
			v.push_back(P{l, r - 1});
			l = r;
		} else {
			l++;
		}
	}
	
//	for (P p: v) cout << p.first << ' ' << p.second << endl;

	if (v.size() == 0) cout << -1 << endl;
	else {
		ll m = -1;
		for (P p: v) {
			if ((p.first - 1 >= 0 && s[p.first - 1] == '-') || (p.second + 1 < n && s[p.second + 1] == '-')) {
				m = max(m, p.second - p.first + 1);
			}
		}
		cout << m << endl;
	}

	return 0;
}