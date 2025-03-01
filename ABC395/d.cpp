#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <functional>
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

	vector<ll> b2l(n + 1);
	vector<ll> l2b(n + 1);
	vector<ll> p2b(n + 1);
	irep(i, n) b2l[i] = l2b[i] = p2b[i] = i;

	while (q--) {
		ll cmd;
		cin >> cmd;
		if (cmd == 1) {
			ll pigeon, to;
			cin >> pigeon >> to;

			p2b[pigeon] = l2b[to];
		} else if (cmd == 2) {
			ll label1, label2;
			cin >> label1 >> label2;

			swap(l2b[label1], l2b[label2]);
			swap(b2l[l2b[label1]], b2l[l2b[label2]]);
		} else {
			ll pigeon;
			cin >> pigeon;

			cout << b2l[p2b[pigeon]] << endl;
		}
	}

	return 0;
}