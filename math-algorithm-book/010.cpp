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
	ll n, ans = 1;
	cin >> n;
	
	rep(i, n) ans *= (i + 1);

	cout << ans << endl;

	return 0;
}