#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define MOD (1000000007)

using namespace std;

vector<vector<ll>> matmulti(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> c(3, vector<ll>(3, 0));
	rep(i, 3) {
		rep(k, 3) {
			rep(j, 3) {
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
	vector<vector<ll>> m(3, vector<ll>(3, 1)), ans(3, vector<ll>(3));

	ll n;
	cin >> n;

	m[1][1] = m[1][2] = m[2][0] = m[2][2] = 0;

	ans = matpow(m, n - 1);

	cout << (ans[0][0]) % MOD << endl;

	return 0;
}