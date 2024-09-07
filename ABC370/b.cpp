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

	vector<vector<ll>> v(105, vector<ll>(105, 0));
	irep(i, n) {
		irep(j, i) {
			cin >> v[i][j];
		}
	}

	ll now = 1;
	irep(j, n) {
		if (now >= j) now = v[now][j];
		else now = v[j][now];
	}

	cout << now << endl;

	return 0;
}