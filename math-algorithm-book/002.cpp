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
	ll a, sum = 0;
	rep(i, 3) {
		cin >> a;
		sum += a;
	}

	cout << sum << endl;

	return 0;
}