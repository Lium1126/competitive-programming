#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	string s;
	cin >> s;

	ll sum = 0;
	for (char c : s) sum += (c - '0');

	cout << sum * 111 << endl;

	return 0;
}