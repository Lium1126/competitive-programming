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
	ll n, k;
	cin >> n >> k;

	ll a, sum = 0;
	rep(i, n) {
		cin >> a;
		sum += a;
	}

	cout << ((k & 1) == (sum & 1) && sum <= k ? "Yes" : "No") << endl;

	return 0;
}