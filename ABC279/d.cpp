#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>
#include <cmath>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

ll A, B;

double f(ll x) {
	return ((double)A / sqrt(x + 1)) + (double)(x * B);
}
	
double df(ll x) {
	return -(double)((double)A / (double)(x + 1)) + (double)B;
}

int main() {
	cin >> A >> B;

	if (A <= B) {
		cout << A << endl;
		return 0;
	}

	ll x = 500000000000000000;
	ll leng = 500000000000000000;
	while (true) {
		double prev = (x == 0 ? A : f(x - 1));
		double next = f(x + 1);
		double now = f(x);
		cout << prev << ' ' << now << ' ' << next << endl;
		if (prev >= now && now <= next) break;

		double r = df(x);
		bool k = (r < 0 ? true : false);
		
		if (k) {
			x += leng / 2;
		} else {
			x -= leng / 2;
		}
		leng = (leng / 2 == 1 ? leng : leng / 2);
	}

	cout << x << endl;

	return 0;
}