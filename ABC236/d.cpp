#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 1;i <= n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;

	vector<vector<ll>> a(2 * n + 1, vector<ll>(2 * n + 1, -1));

	for (ll i = 2 * n - 1;i >= 1;i--) {
		rep(j, i) {
			cin >> a[(2 * n - 1) - i + 1][j];
		}
	}

	/*
	rep(i, 2 * n) {
		rep(j, 2 * n) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	*/

	vector<ll> p;
	rep(i, 2 * n) p.push_back(i);
	
	do {
		cout << "------" << endl;
        for (ll i = 0;i <= 2 * n - 2;i += 2) {
			cout << "(" << p[i] << ", " << p[i + 1] << ")" << endl;
		}
    } while(next_permutation(p.begin(), p.end()));

	return 0;
}