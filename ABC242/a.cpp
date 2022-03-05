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

int main() {
	ll a, b, c, x;
	cin >> a >> b >> c >> x;
	if (x <= a) cout << 1 << endl;
	else if (x <= b) {
		printf("%.12lf\n", (double)((double)c / (double)(b - a)));
	} else cout << 0 << endl;
	return 0;
}