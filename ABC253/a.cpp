#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;

	if ((a <= b && b <= c) || (c <= b && b <= a)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}