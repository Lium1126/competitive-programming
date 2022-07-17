#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

ll n, x, y;

ll convert(bool red, ll level, ll num) {
	if (red) {
		if (level == 1) return 0;
		return convert(true, level - 1, num) + convert(false, level, x * num);
	} else {
		if (level == 1) return num;
		return convert(true, level - 1, num) + convert(false, level - 1, y * num);
	}
}

int main() {
	cin >> n >> x >> y;
	cout << convert(true, n, 1) << endl;
	return 0;
}