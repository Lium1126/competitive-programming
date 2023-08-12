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
	vector<pair<char, ll>> v;
	for (char c : s) v.push_back(make_pair(c, 0));

	ll q;
	cin >> q;

	ll t, x; char c;
	P info;
	info.first = 0;
	info.second = 0;
	rep(timestamp, q) {
		cin >> t >> x >> c;
		if (t == 1) {
			v[x - 1].first = c;
			v[x - 1].second = timestamp;
		}
		if (t == 2) {
			info.first = -1;
			info.second = timestamp;
		}
		if (t == 3) {
			info.first = 1;
			info.second = timestamp;
		}
	}

	rep(i, n) {
		if (info.second < v[i].second) cout << v[i].first;
		else {
			if (info.first == 0) cout << v[i].first;
			else if (info.first == -1) cout << (char)tolower(v[i].first);
			else cout << (char)toupper(v[i].first);
		}
	}
	cout << endl;

	return 0;
}