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
	string s;
	cin >> s;
	s = 'a' + s;

	irep(i, (s.length() - 1) / 2) {
		char tmp = s[2*i-1];
		s[2*i-1] = s[2*i];
		s[2*i] = tmp;
	}
	s.erase(0, 1);
	cout << s << endl;

	return 0;
}