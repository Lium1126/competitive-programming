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
typedef pair<char, ll> P;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;

	vector<P> v;
	rep(i, s.length()) {
		if (s[i] != '/') {
			char target = s[i];
			ll cnt = 0;
			while (i + cnt < s.length() && s[i + cnt] == target) cnt++;
			v.push_back(P{target, cnt});
			i = i + cnt - 1;
		} else {
			v.push_back(P{'/', 1});
		}
	}

	// for (P p : v) cout << p.first << ' ' << p.second << endl;

	ll ans = 0;
	rep(i, v.size()) {
		if (v[i].first == '/') {
			ans = max(ans, 1LL);
			if ((i - 1 >= 0 && v[i - 1].first == '1') && (i + 1 < v.size() && v[i + 1].first == '2')) ans = max(ans, 1 + min(v[i - 1].second, v[i + 1].second) * 2);
		}
	}

	cout << ans << endl;

	return 0;
}