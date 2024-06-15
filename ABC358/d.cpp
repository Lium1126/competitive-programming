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
	ll n, m;
	cin >> n >> m;

	multiset<ll> s;
	vector<ll> v(m);
	ll in;
	rep(i, n) {
		cin >> in;
		s.insert(in);	
	}
	rep(i, m) cin >> v[i];


	sort(v.begin(), v.end(), greater<ll>());

	// rep(i, m) cout << v[i] << endl;

	ll ans = 0;
	rep(i, m) {
		auto it = s.lower_bound(v[i]);
		if (it == s.end()) {
			cout << -1 << endl;
			return 0;
		}

		ans += *it;
		s.erase(it);
	}

	cout << ans << endl;

	return 0;
}