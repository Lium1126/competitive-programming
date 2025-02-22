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

	bool flag;
	do {
		flag = false;
		for (ll i = s.length() - 1;i > 0;i--) {
			if (s[i] == 'A' && s[i - 1] == 'W') {
				s[i] = 'C';
				s[i - 1] = 'A';
				flag = true;
			}
		}
	} while (flag);

	cout << s << endl;

	return 0;
}