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
	ll l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;

	vector<ll> v(101, 0);
	srep(i, l1 + 1, r1) v[i]++;
	srep(i, l2 + 1, r2) v[i]++;

	ll ans = 0;
	rep(i, 101) if (v[i] == 2) ans++; 

	cout << ans << endl;

	return 0;
}