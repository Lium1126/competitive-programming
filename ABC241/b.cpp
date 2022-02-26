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
	ll n, m;
	cin >> n >> m;
	map<ll, ll> a;
	ll in;
	ll b;
	bool flag = true;
	rep(i, n) {
		cin >> in;
		a[in]++;
	}
	rep(i, m) {
		cin >> b;
		if (a[b] <= 0) flag = false;
		else a[b]--;
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}