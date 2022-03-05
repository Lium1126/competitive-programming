#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (998244353)

using namespace std;

vector<vector<ll> > v(1000005, vector<ll>(10, 0));

int main() {
	ll n;
	cin >> n;
	for (ll i = 1;i <= 9;i++) v[1][i] = 1;
	for (ll i = 2;i <= n;i++) {
		for (ll j = 1;j <= 9;j++) {
			if (j == 1) v[i][j] = (v[i - 1][j] + v[i - 1][j + 1]) % MOD;
			else if (j == 9) v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % MOD;
			else v[i][j] = (v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1]) % MOD;
		}
	}
	ll sum = 0;
	for (ll i = 1;i <= 9;i++) sum = (sum + v[n][i]) % MOD;
	cout << sum << endl;
	return 0;
}