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

	vector<ll> p(n + 1), q(n + 1);
	vector<P> v;
	ll in;
	irep(i, n) cin >> p[i];
	irep(i, n) {
		cin >> in;
		q[i] = in;
		v.push_back(P(in, i));
	}

	sort(v.begin(), v.end());

	for (P elem : v) {
		cout << q[p[elem.second]] << ' ';
	}
	cout << endl;

	return 0;
}