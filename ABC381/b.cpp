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
	string s;
	cin >> s;

	if (s.length() % 2 == 1) {
		cout << "No" << endl;
		return 0;
	}

	map<char, ll> m;
	rep(i, s.length() / 2) {
		if (s[2 * i] != s[2 * i + 1]) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (char c : s) {
		m[c]++;
		if (m[c] >= 3) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}