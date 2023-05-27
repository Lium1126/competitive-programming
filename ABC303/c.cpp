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
	ll n, m, h, k;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;

	ll x, y;
	set<P> item;
	rep(i, m) {
		cin >> x >> y;
		item.insert(P{x, y});
	}

	P now = P{0, 0};
	bool ans = true;
	rep(i, n) {
		h--;
		if (s[i] == 'R') now.first++;
		if (s[i] == 'L') now.first--;
		if (s[i] == 'U') now.second++;
		if (s[i] == 'D') now.second--;

		if (h < 0) ans = false;
		if (item.find(now) != item.end() && h < k) {
			item.erase(now);
			h = k; 
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}