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
	ll k;
	cin >> k;

	string s = "";
	while(k != 0) {
		s = ((k & 1) == 1 ? '2' : '0') + s;
		k /= 2;
	}

	cout << s << endl;

	return 0;
}