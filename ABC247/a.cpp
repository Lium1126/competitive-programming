#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	string s;
	cin >> s;
	s = '0' + s;
	rep(i, 4) cout << s[i];
	cout << endl;
	return 0;
}