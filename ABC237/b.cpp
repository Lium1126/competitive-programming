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
	ll h, w;
	cin >> h >> w;

	vector<vector<ll>> b(w, vector<ll>(h));
	rep(i, h) {
		rep(j, w) {
			cin >> b[j][i];
		}
	}

	rep(i, w) {
		rep(j, h) {
			cout << b[i][j] << (j == h - 1 ? '\n' : ' ');
		}
	}

	return 0;
}