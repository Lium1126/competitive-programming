#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll a, b;
	cin >> a >> b;
	if (abs(a - b) == 1) cout << "Yes" << endl;
	else if ((a == 10 && b == 1) || (a == 1 && b == 10)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}