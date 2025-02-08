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

	set<ll> s;
	rep(i, n) s.insert(i + 1);

	ll a;
	rep(i, m) {
		cin >> a;
		if (s.find(a) != s.end()) {
			s.erase(a);
		}
	}

	cout << s.size() << endl;
	for (auto itr = s.begin();itr != s.end();itr++) {
		cout << *itr << ' ';
	}
	cout << endl;

	return 0;
}