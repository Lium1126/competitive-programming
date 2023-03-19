#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ull unsigned long long
#define rep(i, n)     for (ull i = 0;i < n;i++)
#define rrep(i, n)    for (ull i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ull i = 1;i <= n;i++)
#define rirep(i, n)   for (ull i = n;i >= 1;i--)
#define srep(i, s, n) for (ull i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ull, ull> P;
typedef pair<P, ull> PP;

int main() {
	ull l, n, m, ans = 0;
	cin >> l >> n >> m;

	vector<P> a(n), b(m);
	rep(i, n) cin >> a[i].first >> a[i].second;
	rep(i, m) cin >> b[i].first >> b[i].second;

	ull i = 0, j = 0, p = 0, q = 0;
	while (i < n && j < m) {
		if (a[i].first == b[j].first) ans += min(p + a[i].second, q + b[j].second) - max(p, q);
		if (p + a[i].second < q + b[j].second) {
			p += a[i].second;
			i++;
		} else {
			q += b[j].second;
			j++;
		}
	}

	cout << ans << endl;

	return 0;
}