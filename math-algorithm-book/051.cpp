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

	mint denominator = 1, molecule = 1;
	for (ll i = 1;i <= x + y;i++) molecule *= i;
	for (ll i = 1;i <= x;i++) denominator *= i;
	for (ll i = 1;i <= y;i++) denominator *= i;

	cout << (molecule / denominator).val() << endl;

	return 0;
}