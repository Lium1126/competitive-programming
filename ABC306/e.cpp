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

ll ans = 0;
ll n, k, q;
multiset<ll> s1, s2;

void balance() {
	while (s1.size() < k) {
		auto itr = s2.end(); itr--;
		ans += *itr;
		s1.insert(*itr);
		s2.erase(itr);
	}

	if (s1.empty() || s2.empty()) return;

	while (1) {
		auto itr_s1 = s1.begin();
		auto itr_s2 = s2.end(); itr_s2--;
		if (*itr_s1 >= *itr_s2) return;
		ans += (*itr_s2 - *itr_s1);
		ll v_s1 = *itr_s1, v_s2 = *itr_s2;
		s1.erase(itr_s1);
		s2.erase(itr_s2);
		s1.insert(v_s2);
		s2.insert(v_s1);
	}
}

void add(ll v) {
	s2.insert(v);
	balance();
}

void erase(ll v) {
	auto itr = s1.find(v);
	if (itr != s1.end()) {
		ans -= *itr;
		s1.erase(itr);
	} else {
		s2.erase(s2.find(v));
	}
	balance();
}

int main() {
	cin >> n >> k >> q;
	vector<ll> v(n, 0);

	ll x, y;
	rep(i, k) s1.insert(0);
	rep(i, n - k) s2.insert(0);

	while(q--) {
		cin >> x >> y;
		x--;
		
		ll before = v[x];
		v[x] = y;

		add(y);
		erase(before);

/*
		for (auto itr = s2.begin();itr != s2.end();itr++) cout << *itr << ' ';
		cout << "| ";
		for (auto itr = s1.begin();itr != s1.end();itr++) cout << *itr << ' ';
		cout << endl;
*/

		cout << ans << endl;
	}

	return 0;
}