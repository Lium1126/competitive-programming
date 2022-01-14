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
	ll n, a, sum = 0;
	cin >> n;

	rep(i, n) {
		cin >> a;
		sum += a;
	}

	cout << sum << endl;

	return 0;
}