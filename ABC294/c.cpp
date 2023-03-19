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
	vector<ll> a(n), b(m), s;
	rep(i, n) {
		cin >> a[i];
		s.push_back(a[i]);
	}
	rep(i, m) {
		cin >> b[i];
		s.push_back(b[i]);
	}
	sort(s.begin(), s.end());

	rep(i, n) {
		cout << (lower_bound(s.begin(), s.end(), a[i]) - s.begin()) + 1 << ' ';
	}
	cout << endl;
	rep(i, m) {
		cout << (lower_bound(s.begin(), s.end(), b[i]) - s.begin()) + 1 << ' ';
	}
	cout << endl;
	return 0;
}