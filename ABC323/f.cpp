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
#define ull unsigned long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ull, ull> P;

#define GETA (100000000000000000)

ull dist(P a, P b) {
	ull x1, x2;
	if (a.first > b.first) x1 = a.first - b.first;
	else x1 = b.first - a.first;

	if (a.second > b.second) x2 = a.second - b.second;
	else x2 = b.second - a.second;

	return x1 + x2;
}

int main() {
	P a, b, c;
	ll in;
	ull tmp;

	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	a.first = tmp;
	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	a.second = tmp;

	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	b.first = tmp;
	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	b.second = tmp;

	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	c.first = tmp;
	cin >> in;
	tmp = (ull)((ll)(GETA) + in);
	c.second = tmp;

	if (b.first == c.first) {
		if (b.first == a.first) {
			if ((b.second < a.second && b.second < c.second) || (b.second > a.second && b.second > c.second)) {
				cout << (dist(a, b) - 1 + 4) + dist(b, c) << endl;
			} else {
				cout << dist(a, c) - 1 << endl;
			}
		} else {
			if (b.second == a.second) {
				cout << (dist(a, b) - 1) + 2 + dist(b, c) << endl;
			} else if ((b.second < a.second && b.second < c.second) || (b.second > a.second && b.second > c.second)) {
				cout << (dist(a, b) - 1 + 2) + dist(b, c) << endl;
			} else {
				cout << dist(a, b) - 1 + dist(b, c) << endl;
			}
		}
	}

	else if (b.second == c.second) {
		if (b.second == a.second) {
			if ((b.first < a.first && b.first < c.first) || (b.first > a.first && b.first > c.first)) {
				cout << (dist(a, b) - 1 + 4) + dist(b, c) << endl;
			} else {
				cout << dist(a, c) - 1 << endl;
			}
		} else {
			if (b.first == a.first) {
				cout << (dist(a, b) - 1) + 2 + dist(b, c) << endl;
			} else if ((b.first < a.first && b.first < c.first) || (b.first > a.first && b.first > c.first)) {
				cout << (dist(a, b) - 1 + 2) + dist(b, c) << endl;
			} else {
				cout << dist(a, b) - 1 + dist(b, c) << endl;
			}
		}
	}

	else if (
		((b.first < a.first && b.first < c.first) || (b.first > a.first && b.first > c.first)) &&
		((b.second < a.second && b.second < c.second) || (b.second > a.second && b.second > c.second))
	) {
		cout << dist(a, b) + 1 + dist(b, c) + 2 << endl;
	} else  {
		cout << (dist(a, b) - 1) + dist(b, c) + 2 << endl;
	}

	return 0;
}