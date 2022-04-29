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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll takahashi = a * 3600 + b * 60;
	ll aoki = c * 3600 + d * 60 + 1;
	cout << (takahashi < aoki ? "Takahashi" : "Aoki") << endl;
	return 0;
}