#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <stdio.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;

	ll a, c;
	char b, d;
	atcoder::dsu uf(n);
	ll lope = 0;
	rep(i, m) {
		cin >> a >> b >> c >> d;
		a--; c--;
		if (uf.same(a, c)) lope++;
		uf.merge(a, c);
	}

	cout << lope << ' ' << uf.groups().size() - lope << endl;

	return 0;
}