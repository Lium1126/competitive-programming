#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

#define DEG (M_PI / 3)

int main() {
	double a, b;
	cin >> a >> b;
	if (b > a) swap(a, b);

	double ans = double(b);
	double low = 0, high = a;
	double i = 0;
	while (low < high && (high - low) > pow(10.0, -9.0)) {
		// 頂点B: (b, i)
		// x2 = x1 * cos(α) - y1 * sin(α)
		// y2 = x1 * sin(α) + y1 * cos(α)
		double x2 = b * cos(DEG) - i * sin(DEG);
		double y2 = b * sin(DEG) + i * cos(DEG);

		//cout << "(" << x2 << ", " << y2 << ")" << endl;

		if (0.0 <= x2 && x2 <= b && 0.0 <= y2 && y2 <= a) { // 長方形の中
			ans = max(ans, sqrt(pow(b, 2.0) + pow(i, 2.0)));
			low = i;
		} else { // 長方形の外
			high = i;
		}
		i = (low + high) / 2.0;
	}

	printf("%.20lf\n", ans);

	return 0;
}