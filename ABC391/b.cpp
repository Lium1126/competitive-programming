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
#define irep(i, n)    for (ll i = 0;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll n, m;
	cin >> n >> m;

	vector<string> s(n), t(m);

	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];

	irep(i, n - m) {
		irep(j, n - m) {
			bool flag = true;
			rep(k, m) {
				rep(l, m) {
					if (s[i + k][j + l] != t[k][l]) {
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}

			if (flag) {
				cout << i + 1 << ' ' << j + 1 << endl;
				return 0;
			}
		}
	}

	return 0;
}
