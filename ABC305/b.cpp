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
	char p, q;
	cin >> p >> q;

	ll i = p - 'A', j = q - 'A';
	if (i > j) swap(i, j);

	vector<ll> v(7, 0);
	v[1] = 3;
	v[2] = 4;
	v[3] = 8;
	v[4] = 9;
	v[5] = 14;
	v[6] = 23;

	cout << v[j] - v[i] << endl;
	
	return 0;
}