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
	ll n;
	cin >> n;
	vector<vector<string>> v(n, vector<string>(2));
	vector<vector<bool>> b(n, vector<bool>(2));
	rep(i, n) {
		cin >> v[i][0] >> v[i][1];
		b[i][0] = b[i][1] = true;
	}

	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			rep(k, 2) {
				if (v[i][k] == v[j][0] || v[i][k] == v[j][1]) b[i][k] = false;
			}
		}
	}

	string ans = "Yes";
	rep(i, n) if (!b[i][0] && !b[i][1]) ans = "No";
	cout << ans << endl;

	return 0;
}