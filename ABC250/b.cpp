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
	ll n, a, b;
	cin >> n >> a >> b;
	char c[2] = {'.', '#'};
	rep(i, n * a) {
		rep(j, n * b) {
			ll x, y;
			y = i / a; x = j / b;
			cout << c[(x + y) % 2];
		}
		cout << endl;
	}
	return 0;
}