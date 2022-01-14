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
	ll x, y;
	cin >> x >> y;

	ll a = 2 * x - y, b = 2 * y - x;

	if (a % 3 || b % 3) { cout << 0 << endl; return 0; }
	else if (a < 0 || b < 0) { cout << 0 << endl; return 0; }
	else {
		a /= 3, b /= 3;

		// {a+b}C{a}を計算
		mint denominator = 1, molecule = 1;
		for (ll i = 1;i <= a + b;i++) molecule *= i;
		for (ll i = 1;i <= a;i++) denominator *= i;
		for (ll i = 1;i <= b;i++) denominator *= i;
		cout << (molecule / denominator).val() << endl;
	}

	return 0;
}