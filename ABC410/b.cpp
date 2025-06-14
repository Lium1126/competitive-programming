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
	ll n, q;
	cin >> n >> q;

	vector<ll> num(n + 1, 0);

	ll x;
	while(q--) {
		cin >> x;

		if (x >= 1) {
			num[x]++;
			cout << x << " ";
			continue;
		}
		
		set<P> s;
		irep(i, n) {
			s.insert(P{num[i], i});
		}

		ll ans = (*(s.begin())).second;
		cout << ans << " ";
		num[ans]++;
	}
	cout << endl;

	return 0;
}
