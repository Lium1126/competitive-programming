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
typedef pair<ll, P> PP;

int main() {
	ll n, m, k;
	cin >> n >> m >> k;

	ll tmp = k - n;
	if (tmp != 0 && tmp % 2 == 1) {
		cout << "No" << endl;
		return 0;
	}

	if (tmp / 2 > ((n - (n%2 ? 1 : 0)) * (m - 1)) / 2) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	vector<vector<char>> maze(2 * n + 1, vector<char>(2 * m + 1, '.'));
	rep(i, 2 * m + 1) maze[0][i] = '+';
	rep(i, 2 * m + 1) maze[2 * n][i] = '+';
	rep(i, 2 * n + 1) maze[i][0] = '+';
	rep(i, 2 * n + 1) maze[i][2 * m] = '+';
	maze[0][2 * m - 1] = 'S';
	maze[2 * n][2 * m - 1] = 'G';
	for (ll i = 2;i < 2 * n + 1;i += 2) {
		for (ll j = 2;j < 2 * m + 1;j += 2) {
			maze[i][j] = '+';
		}
	}
	for (ll i = 1;i < 2 * n + 1;i += 2) {
		for (ll j = 1;j < 2 * m + 1;j += 2) {
			maze[i][j] = 'o';
		}
	}

	ll pairs = tmp / 2;
	for (ll row  = 2;row < 2 * n;row += 2) {
		// 何マス左に行くか
		ll cnt = min(pairs, m - 1);
		pairs -= cnt;
		rep(i, cnt) {
			maze[row][2 * m - (1 + 2 * i)] = '-';
			maze[row + 2][(m - 1 - cnt) + 2 + (2 * i)] = '-';
		}
		maze[row - 1][2 * m - (2 + 2 * cnt)] = '|';
		maze[row + 1][2 * m - (2 + 2 * cnt)] = '|';
	}

	rep(i, 2 * n + 1) {
		rep(j, 2 * m + 1) {
			cout << maze[i][j];
		}
		cout << endl;
	}

	return 0;
}