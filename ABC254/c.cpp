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
	ll n, k;
	cin >> n >> k;
	
	vector<vector<ll>> a(k, vector<ll>());
	ll in;
	rep(i, n) {
		cin >> in;
		a[i % k].push_back(in);
	}

	rep(i, k) sort(a[i].begin(), a[i].end());

	vector<ll> b;
	rep(i, n) {
		b.push_back(a[i % k][i / k]);
	}

//	rep(i, n) cout << b[i] << ' ';
//	cout << endl;

	bool f = true;
	rep(i, n - 1) if (b[i] > b[i + 1]) f = false;

	cout << (f ? "Yes" : "No") << endl;

	return 0;
}