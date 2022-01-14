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

struct Matrix {
	ll p[2][2] = {{0, 0}, {0, 0}};
};

Matrix multi(Matrix a, Matrix b) {
	Matrix c;
	rep(i, 2) {
		rep(k, 2)  {
			rep(j, 2) {
				c.p[i][j] += a.p[i][k] * b.p[k][j];
				c.p[i][j] %= MOD;
			}
		}
	}
	return c;
}

Matrix pow(Matrix x, ll n) {
	Matrix p = x, q;
	bool flag = false;

	rep(i, 60) {
		if ((n & (1LL << i)) != 0LL) {
			if (!flag) q = p, flag = true;
			else q = multi(q, p);
		}
		p = multi(p, p);
	}

	return q;
}

int main() {
	ll n;
	cin >> n;

	Matrix base;
	base.p[0][0] = base.p[0][1] = base.p[1][0] = 1;

	Matrix ans = pow(base, n - 1);
	cout << (ans.p[1][0] + ans.p[1][1]) % MOD << endl;

	return 0;
}