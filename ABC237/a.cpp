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
	double n;
	cin >> n;

	cout << (-pow(2, 31) <= n && n < pow(2, 31) ? "Yes" : "No") << endl;

	return 0;
}