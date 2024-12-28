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
typedef pair<P, char> PC;

int main() {
	ll n, m;
	cin >> n >> m;
	
	ll x, y;
	char c;
	vector<PC> v;
	map<ll, ll> bmp;
	rep(i, m) {
		cin >> x >> y >> c;
		if (c == 'B') {
			bmp[x] = max(bmp[x], y);
		}
		v.push_back(PC(P(x, y), c));
	}

	ll bx = 0;
	sort(v.begin(), v.end(), greater<PC>());

	rep(i, v.size()) {
		if (v[i].second == 'B') {
			bx = max(bx, v[i].first.second);
		} else {
			if (bmp[v[i].first.first] > v[i].first.second) {
				cout << "No" << endl;
				return 0;
			}
			if (bx >= v[i].first.second) {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	cout << "Yes" << endl;

	return 0;
}