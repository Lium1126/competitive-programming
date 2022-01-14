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

mint mypow(mint x, ll n) {
	if (n == 1) return x;
	if (n % 2 == 0) return mypow(x * x, n / 2);
	else return mypow(x * x, n / 2) * x;
}

int main() {
	ll a, b;
	cin >> a >> b;

	mint x;
	x = a;

	cout << mypow(x, b).val() << endl;

	return 0;
}