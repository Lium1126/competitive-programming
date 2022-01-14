#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef struct {
	vector<vector<double>> m = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0}
	};
} Matrix;

Matrix multi(Matrix a, Matrix b) {
	Matrix c;
	rep(i, 3) {
		rep(j, 3) {
			rep(k, 3) {
				c.m[i][j] += a.m[i][k] * b.m[k][j];
			}
		}
	}
	return c;
}

Matrix mpow(Matrix a, ll n) {
	if (n == 1) return a;
	if (!(n % 2)) return mpow(multi(a, a), n / 2);
	else return multi(mpow(multi(a, a), n / 2), a);
}

int main() {
	ll q;
	cin >> q;

	double x, y, z;
	ll t;
	rep(cnt, q) {
		cin >> x >> y >> z >> t;

		Matrix a;
		a.m[0][0] = 1.0 - x; a.m[0][1] = y;
		a.m[1][1] = 1.0 - y; a.m[1][2] = z;
		a.m[2][2] = 1.0 - z; a.m[2][0] = x;

		Matrix ans = mpow(a, t);
		printf("%.12lf %.12lf %.12lf\n", 
			ans.m[0][0] + ans.m[0][1] + ans.m[0][2],
			ans.m[1][0] + ans.m[1][1] + ans.m[1][2],
			ans.m[2][0] + ans.m[2][1] + ans.m[2][2]);
	}

	return 0;
}