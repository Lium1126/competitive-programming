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
	string s;
	cin >> s;

	vector<ll> x(26, 0);
	rep(i, 26) {
		char target = 'A' + i;
		rep(j, s.length()) {
			if (s[j] == target) x[i] = j;
		}
	}

	ll ans = 0;
	rep(i, 25) {
		ans += abs(x[i] - x[i + 1]);
	}
	cout << ans << endl;

	return 0;
}