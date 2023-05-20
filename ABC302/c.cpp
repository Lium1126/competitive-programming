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
	ll n, m;
	cin >> n >> m;
	vector<string> v(n);
	rep(i, n) cin >> v[i];

	bool flag = false;
	do {
/*
		cout << "===========" << endl;
		for (string s : v) cout << s << endl;
		cout << "===========" << endl;
*/
		ll one_cnt = 0;
		rep(i, v.size() - 1) {
			ll cnt = 0;
			rep(j, v[i].length()) {
				if (v[i][j] != v[i + 1][j]) cnt++;
			}
//			cout << v[i] << ' ' << v[i + 1] << " => " << cnt << endl;
			if (cnt == 1) one_cnt++;
		}
		if (one_cnt == v.size() - 1) flag = true;

	} while (next_permutation(v.begin(), v.end()));

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}