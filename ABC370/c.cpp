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
	string s, t;
	cin >> s >> t;

	ll len = s.length();
	vector<string> ans;
	while (s != t) {
		string m = "";
		rep(i, len) m += 'z';

		string cs;
		rep(i, len) {
			cs = s;
			if (cs[i] == t[i]) continue;
			cs[i] = t[i];
			if (m > cs) m = cs;
		}

		ans.push_back(m);
		s = m;
	}

	cout << ans.size() << endl;
	rep(i, ans.size()) cout << ans[i] << endl;

	return 0;
}