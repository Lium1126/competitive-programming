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
	ll n;
	cin >> n;

	bool flag = true;
	ll h, now = 0;
	rep(i, n) {
		cin >> h;
		if (now < h && flag) now = h;
		else flag = false;
	}

	cout << now << endl;

	return 0;
}