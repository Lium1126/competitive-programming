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
	string s, t;
	cin >> s >> t;

	map<char, ll> sm, tm;
	ll sa = 0, ta = 0;
	for (char c : s) {
		if (c != '@') sm[c]++;
		else sa++;
	}
	for (char c : t) {
		if (c != '@') tm[c]++;
		ta++;
	}

	set<char> al;
	al.insert('a'); al.insert('t'); al.insert('c'); al.insert('o'); al.insert('d'); al.insert('e'); al.insert('r');
	for (ll i = 0;i < 26;i++) {
		char c = 'a' + i;
		if (al.find(c) == al.end() && sm[c] != tm[c]) {
			cout << "No" << endl;
			return 0;
		}
	}

	ll sum = 0;
	for (ll i = 0;i < 26;i++) {
		char c = 'a' + i;
		if (al.find(c) != al.end() && tm[c] > sm[c]) sum += tm[c] - sm[c];
	}
	if (sum > sa) {
		cout << "No" << endl;
		return 0;
	}

	sum = 0;
	for (ll i = 0;i < 26;i++) {
		char c = 'a' + i;
		if (al.find(c) != al.end() && tm[c] < sm[c]) sum += sm[c] - tm[c];
	}
	if (sum > ta) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	return 0;
}