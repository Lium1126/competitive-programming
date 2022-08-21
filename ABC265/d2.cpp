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
	ll n, p, q, r, a, sum = 0;
	cin >> n >> p >> q >> r;
	set<ll> s;
	s.insert(0);

	rep(i, n) {
		cin >> a;
		sum += a;
		s.insert(sum);
	}

	for (auto itr = s.begin();itr != s.end();itr++) {
		ll x = *itr;
		if (s.find(x + p) != s.end() && s.find(x + p + q) != s.end() && s.find(x + p + q + r) != s.end()) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	
	return 0;
}