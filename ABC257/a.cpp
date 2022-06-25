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
	ll n, x;
	cin >> n >> x;

	string s = "";
	rep(i, 26) {
		rep(j, n) s += ('A' + i);
	}

	cout << s[x - 1] << endl;

	return 0;
}