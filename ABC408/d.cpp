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
	ll t;
	cin >> t;

	ll n;
	while(t--) {
		cin >> n;
		string s;
		cin >> s;

		ll cnt = 0;
		ll ml = 0;
		rep(i, n) {
			if (s[i] == '0') {
				continue;
			}

			ll l = 0;
			do {
				cnt++;
				l++;
				i++;
			} while (i < n && s[i] == '1');

			ml = max(ml, l);
		}

		cout << cnt - ml << endl;
	}

	return 0;
}