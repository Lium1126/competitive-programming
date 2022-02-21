#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef pair<ll, ll> P;

int main() {
	ll n, x;
	cin >> n >> x;
	vector<vector<bool>> visited(105, vector<bool>(10005, false));
	visited[0][0] = true;

	ll a, b;
	rep(i, n) {
		cin >> a >> b;
		rep(j, visited[i].size()) {
			if (visited[i][j]) {
				if (j + a <= x) visited[i + 1][j + a] = true;
				if (j + b <= x) visited[i + 1][j + b] = true;
			}
		}
	}

	cout << (visited[n][x] ? "Yes" : "No") << endl;

	return 0;
}