#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (1000000000)

using namespace std;

vector<vector<ll>> matmulti(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> c(2, vector<ll>(2, 0));
	rep(i, 2) {
		rep(k, 2) {
			rep(j, 2) {
				c[i][j] += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
				c[i][j] %= MOD;
			}
		}
	}
	return c;
}

vector<vector<ll>> matpow(vector<vector<ll>> x, ll n) {
	if (n == 1) return x;
	if (n % 2 == 0) return matpow(matmulti(x, x), n / 2);
	else return matmulti(matpow(matmulti(x, x), n / 2), x);
}

int main() {
	vector<vector<ll>> m(2, vector<ll>(2, 1)), ans(2, vector<ll>(2));
	m[1][1] = 0;

	ll n;
	cin >> n;

	ans = matpow(m, n - 1);

	cout << (ans[1][0] + ans[1][1]) % MOD << endl;

	return 0;
}