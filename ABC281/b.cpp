#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <regex>
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

	regex re(R"(([A-Z][0-9]{6}[A-Z])+)");


	bool f = regex_match(s, re);
	if (f) {
		ll b = 1, tmp = 0;
		for (ll i = 6;i >= 1;i--) {
			tmp += (s[i] - '0') * b;
			b *= 10;
		}
		// cout << tmp << endl;
		if (100000 <= tmp && tmp <= 999999) cout << "Yes" << endl;
		else cout << "No" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}