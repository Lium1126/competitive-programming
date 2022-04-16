#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	char n = '0';
	map<char, bool> m;
	rep(i, 10) m[n + i] = true;
	string s; cin >> s;
	for (char x : s) m[x] = false;
	rep(i, 10) if (m[n + i]) printf("%c\n", (char)(n + i));

	return 0;
}