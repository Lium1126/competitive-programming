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
	string s;
	cin >> n >> s;

	ll t = 0, a = 0;
	for (char c : s) {
		if (c == 'T') t++;
		else a++;
	}

	if (t > a) cout << "T" << endl;
	else if (a > t) cout << "A" << endl;
	else cout << (s[s.length() - 1] == 'T' ? "A" : "T") << endl;

	return 0;
}