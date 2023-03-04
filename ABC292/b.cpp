#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, q;
	cin >> n >> q;
	map<ll, ll> m;
	ll c, x;
	rep(i, q) {
		cin >> c >> x;
		if (c == 1) {
			m[x]++;
		} else if (c == 2) { 
			m[x] += 2;
		} else {
			cout << (m[x] >= 2 ? "Yes" : "No" ) << endl;
		}
	}
	return 0;
}