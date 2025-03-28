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
	ll n;
	cin >> n;

	ll a;
	map<ll, vector<ll>> m;
	irep(i, n) {
		cin >> a;
		m[a].push_back(i);
	}

	for (auto itr = m.rbegin();itr != m.rend();itr++) {
		if (itr->second.size() == 1) {
			cout << itr->second[0] << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}