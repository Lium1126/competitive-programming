#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	ll n;
	cin >> n;
	vector<vector<char>> v(n, vector<char>(n));

	rep(i, n) {
		rep(j, n) {
			cin >> v[i][j];
		}
	}

	string ans = "correct";
	rep(i, n - 1) {
		for (ll j = i + 1;j < n;j++) {
			if (!(v[i][j] == 'W' && v[j][i] == 'L' ||
				v[i][j] == 'L' && v[j][i] == 'W' || 
				v[i][j] == 'D' && v[j][i] == 'D')) ans = "incorrect";
		}
	}

	cout << ans << endl;

	return 0;
}