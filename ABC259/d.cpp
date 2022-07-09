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

typedef struct {
	ll x, y, r;
} P;

ll dist(P a, P b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int main() {
	ll n;
	cin >> n;
	ll sx, sy, tx, ty, sn, tn;
	cin >> sx >> sy >> tx >> ty;
	vector<P> cir(n + 1);
	ll x, y, r; 
	irep(i, n) {
		cin >> x >> y >> r;
		P p; p.x = x; p.y = y; p.r = r;
		cir[i] = p;
		if ((sx - x) * (sx - x) + (sy - y) * (sy - y) == r * r) sn = i;
		if ((tx - x) * (tx - x) + (ty - y) * (ty - y) == r * r) tn = i;
	}

	atcoder::dsu uf(n + 1);
	irep(i, n - 1) {
		for (ll j = i + 1;j <= n;j++) {
			if (abs(cir[i].r - cir[j].r) * abs(cir[i].r - cir[j].r) <= dist(cir[i], cir[j]) &&
				dist(cir[i], cir[j]) <= (cir[i].r + cir[j].r) * (cir[i].r + cir[j].r)) uf.merge(i, j);
		}
	}

	cout << (uf.same(sn, tn) ? "Yes" : "No") << endl;

	return 0;
}