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
#define MINF (-(1 << 9))

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll n;
	cin >> n;

	ll f, s;
	map<ll, vector<ll>> m;
	rep(i, n) {
		cin >> f >> s;
		m[f].push_back(s);
	}

	for(auto itr = m.begin(); itr != m.end(); ++itr) {
        sort(itr->second.begin(), itr->second.end(), greater<ll>());
    }
/*
	for(auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << itr->first << ':';
		for (ll out : itr->second) cout << out << ' ';
		cout << endl;
	}
*/

	ll ans = MINF;
	for(auto itr = m.begin(); itr != m.end(); ++itr) {
		if ((itr->second).size() >= 2) {
			ans = max(ans, m[itr->first][0] + m[itr->first][1] / 2);
		}
	}

	vector<ll> tmp;
	for(auto itr = m.begin(); itr != m.end(); ++itr) {
		tmp.push_back(m[itr->first][0]);
	}
	sort(tmp.begin(), tmp.end(), greater<ll>());
	ans = max(ans, tmp[0] + tmp[1]);

	cout << ans << endl;

	return 0;
}