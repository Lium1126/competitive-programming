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
	ll x= 0, y = 0;
	ll n;
	string s;
	cin >> n >> s;
	ll dir = 1;

	for (char c : s) {
		if (c == 'S') {
			if (dir == 0) y++;
			else if (dir == 1) x++;
			else if (dir == 2) y--;
			else x--;
		} else {
			dir = (dir + 1) % 4;
		}
	}

	cout << x << ' ' << y << endl;

	return 0;
}