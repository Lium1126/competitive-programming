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
	ll a, b;
	cin >> a >> b;
	a--, b--;

	swap(s[a], s[b]);

	cout << s << endl;

	return 0;
}