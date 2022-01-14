#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;
using mint = atcoder::modint998244353;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	mint A, B, C, ans = 1;
	A = a, B = b, C = c;

	ans *= ((A * (A + 1)) / 2);
	ans *= ((B * (B + 1)) / 2);
	ans *= ((C * (C + 1)) / 2);

	cout << ans.val() << endl;

	return 0;
}