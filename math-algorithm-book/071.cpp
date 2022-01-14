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
	ll a, b, c;
} Line;

vector<Line> l(505);

bool check(double x, double y, ll n) {
	bool ret = true;
	rep(i, n) if (l[i].a * x + l[i].b * y > (double)l[i].c) ret = false;
	return ret;
}

int main() {
	ll n;
	cin >> n;

	rep(i, n) cin >> l[i].a >> l[i].b >> l[i].c;

	double ans = 0.0;
	rep(i, n - 1) {
		for (ll j = i + 1;j < n;j++) {
			if (l[i].a * l[j].b == l[j].a * l[i].b) continue;

			double x = (double)(l[i].c * l[j].b - l[j].c * l[i].b) / (double)(l[i].a * l[j].b - l[j].a * l[i].b);
			double y = (double)(l[i].c * l[j].a - l[j].c * l[i].a) / (double)(l[i].b * l[j].a - l[j].b * l[i].a);
			if (check(x - 0.00000001, y - 0.00000001, n)) ans = max(ans, x + y);
		}
	}

	printf("%.12lf\n", ans);

	return 0;
}