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

map<ll,ll> mp;

ll f(ll n) {
	if (n == 0) return mp[n] = 1;
	if (mp[n] != 0) return mp[n];
	return mp[n] = f(n / 2) + f(n / 3);
}

int main() {
	ll n;
	cin >> n;

	cout << f(n) << endl;
	return 0;
}