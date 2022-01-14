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
	ll n;
	cin >> n;
	n++;

	bool first_win = true;
	ll mask = 1;
	rep(i, 60) {
		if (mask == n) first_win = false;
		mask <<= 1;
	}

	cout << (first_win ? "First" : "Second") << endl;

	return 0;
}