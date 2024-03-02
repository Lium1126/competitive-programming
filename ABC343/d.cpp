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
	ll n, t;
	cin >> n >> t;

	ll a, b;
	vector<ll> v(n, 0);
	set<ll> s;
	s.insert(0);
	map<ll, ll> m;
	m[0] = n;
	while (t--) {
		cin >> a >> b;
		a--;

		m[v[a]]--;
		if (m[v[a]] == 0) s.erase(v[a]);
		s.insert(v[a] + b);
		m[v[a] + b]++;
		v[a] += b;

		// for (auto itr = s.begin();itr != s.end();itr++) {
		// 	cout << *itr << ' ';
		// }
		// cout << endl;

		cout << s.size() << endl;
	}

	return 0;
}