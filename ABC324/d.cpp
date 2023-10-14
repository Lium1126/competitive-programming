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

bool same(vector<char> a, vector<char> b) {
	if (a.size() != b.size()) return false;
	rep(i, a.size()) if (a[i] != b[i]) return false;
	return true;
}

int main() {
	ll n;
	cin >> n;

	string s;
	cin >> s;

	vector<char> p;
	rep(i, n) p.push_back(s[i]);

	sort(p.begin(), p.end(), greater<char>());

	ll m = 0;
	rep(i, n) m *= 10, m += p[i] - '0';
//	cout << m << endl;

	ll ans = 0;
	for (ll i = 0;i * i <= m;i++) {
		ll sq = i * i;

		vector<char> v;
		while (sq != 0) {
			v.push_back((char)('0' + (sq % 10)));
			sq /= 10;
		}
		sort(v.begin(), v.end(), greater<char>());
		while (v.size() < p.size()) v.push_back('0');

		if (same(p, v)) ans++;
	}

	cout << ans << endl;;

	return 0;
}