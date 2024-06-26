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
	ll n, a;
	cin >> n >> a;
	vector<ll> t(n);
	rep(i, n) cin >> t[i];

	ll time = t[0] + a;
	cout << time << endl;
	for (ll i = 1;i < n;i++) {
		if (t[i] < time) {
			time = time + a;
			cout << time << endl;
		} else {
			time = t[i] + a;
			cout << time << endl;
		}
	}

	return 0;
}