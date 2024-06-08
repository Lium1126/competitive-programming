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

vector<vector<char>> maps(800, vector<char>(800));

ll power(ll n, ll x) {
	ll tmp = 1;
	rep(i, x) tmp *= n;
	return tmp;
}

void solve(ll level, P ul, P lr) {
	if (level == 0) {
		maps[ul.second][ul.first] = '#';
		return;
	}

	rep(i, 3) {
		rep(j, 3) {
			P ful = P{ul.first + power(3, level - 1) * j, ul.second + power(3, level - 1) * i};
			P flr = P{ful.first + power(3, level - 1) - 1, ful.second + power(3, level - 1) - 1};

			if (i == 1 && j == 1) {
				srep(i, ful.second, flr.second) {
					srep(j, ful.first, flr.first) {
						maps[i][j] = '.';
					}
				}
			} else {
				solve(level - 1, ful, flr);
			}
		}
	}
}

int main() {
	ll n;
	cin >> n;

	P ul(P{0, 0}), lr(P{power(3, n), power(3, n)});
	solve(n, ul, lr);

	rep(i, power(3, n)) {
		rep(j, power(3, n)) {
			cout << maps[i][j];
		}
		cout << endl;
	}

	return 0;
}