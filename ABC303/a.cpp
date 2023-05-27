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
	string s, t;
	cin >> s >> t;

	bool f = true;
	rep(i, n) {
		if (!(s[i] == t[i] || 
			s[i] == 'l' && t[i] == '1' ||
			s[i] == '1' && t[i] == 'l' ||
			s[i] == 'o' && t[i] == '0' || 
			s[i] == '0' && t[i] == 'o')) {
				f = false;
			}
	}

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}