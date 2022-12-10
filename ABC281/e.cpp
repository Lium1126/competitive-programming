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
	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n);
	rep(i, n) cin >> a[i];

	multiset<ll> s;
	rep(i, m) s.insert(a[i]);

	// for (auto itr = s.begin();itr != s.end();itr++) cout << *itr << ' ';
	// cout << endl;

	rep(i, n - m + 1) {
		auto itr = s.begin();
		ll sum = 0;
		for (ll j = 0;j < k;j++, itr++) sum += *itr;

		cout << sum << ' ';

		if (i < n - m) {
			s.erase(s.lower_bound(a[i]));
			s.insert(a[i + m]);

			// for (auto itr = s.begin();itr != s.end();itr++) cout << *itr << ' ';
			// cout << endl;
		}
	}
	cout << endl;

	return 0;
}