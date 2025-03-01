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

	
	vector<vector<char>> v(n + 1, vector<char>(n + 1, '.'));

	irep(i, n) {
		ll j = n + 1 - i;
		if (i <= j) {
			char target = '#';
			if (i % 2 == 0) target = '.';
			for (ll y = i;y <= j;y ++) for (ll x = i;x <= j;x++) v[y][x] = target;
		}
	}

	irep(i, n) {
		irep(j, n) cout << v[i][j];
		cout << endl;
	}

	return 0;
}