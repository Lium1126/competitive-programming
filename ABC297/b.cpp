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
	vector<ll> b, r;
	ll k = 0;
	rep(i, s.length()) {
		if (s[i] == 'B') b.push_back(i);
		if (s[i] == 'R') r.push_back(i);
		if (s[i] == 'K') k = i;
	}

	if ((b[0] + b[1]) % 2 == 1 && r[0] < k && k < r[1]) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}