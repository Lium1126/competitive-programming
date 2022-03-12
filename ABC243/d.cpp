#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

ll mypow(ll x, ll a) {
	if (a == 0) return 1;
	if (a == 1) return x;
	if (a % 2 == 0) return mypow(x * x, a / 2);
	else return mypow(x * x, a / 2) * x;
}

int main() {
	unsigned ll n, x;
	string s;
	cin >> n >> x;
	cin >> s;

	ll mul = 0, add = 0;
	rep(i, n) {
//		if (i == 0 && s[i] == 'U' && x % 2) x--;
		if (s[i] == 'U') mul--, add /= 2;
		else if (s[i] == 'L') mul++, add *= 2;
		else mul++, add = add * 2 + 1;
	}

	if (mul < 0) cout << x / mypow(2, abs(mul)) + add << endl;
	else cout << x * mypow(2, mul) + add << endl;

	return 0;
}