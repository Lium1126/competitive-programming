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

#define ll unsigned long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

string convert(string s) {
	string ret = "";
	for (char c : s) {
		if (islower(c)) ret.push_back(toupper(c));
		else ret.push_back(tolower(c));
	}
	return ret;
}

ll func(ll n) {
	ll cnt = 0;
	while (n != 0) {
		cnt += n % 2;
		n /= 2;
	}
	
    return (cnt & 1) ^ 1;
}

string rotate(string s) {
	s = s[s.length() - 1] + s;
	s.pop_back();
	return s;
}

int main() {
	vector<string> s(2);
	cin >> s[1];
	s[0] = convert(s[1]);
	s[0] = rotate(s[0]);
	s[1] = rotate(s[1]);

	ll q, k;
	cin >> q;
	ll n = s[1].length();

	vector<char> ans;
	while (q--)	{
		cin >> k;

		ll tmp = (k - 1) / n;
		ll a = func(tmp);

		// cout << tmp << ' ' << a << "->" << s[a][k % n] << endl;

		ans.push_back(s[a][k % n]);
	}

	for (char c : ans) {
		cout << c << ' ';
	}
	cout << endl;
	
	return 0;
}