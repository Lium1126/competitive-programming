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
	vector<ll> a(10);
	rep(i, 10) cin >> a[i];
	ll now = 0;
	rep(i, 3) now = a[now];
	cout << now << endl;
	return 0;
}