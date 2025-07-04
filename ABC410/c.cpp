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
	vector<ll> v(n, 0);
	rep(i, n) v[i] = i + 1;
	ll head = 0;

	while (q--) {
		ll type, p, x, k;
		cin >> type;
		if (type == 1) {
			cin >> p >> x;
			p--;
			v[(head + p) % n] = x;
		} else if (type == 2) {
			cin >> p;
			p--;
			cout << v[(head + p) % n] << endl;
		} else if (type == 3) {
			cin >> k;
			head = (head + k) % n;
		}
	}

	return 0;
}