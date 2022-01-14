#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
	ll n;
	cin >> n;

	mint x = 4;
	x = (x.pow(n + 1) - 1) / 3;
	cout << x.val() << endl;

	return 0;
}