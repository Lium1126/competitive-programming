#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef struct 
{
	double x, y;
} P;

ll n, k;
vector<P> v(305);

int main() {
	cin >> n >> k;
	set<pair<double, double>> ans;
	double x, y;
	rep(i, n) {
		cin >> x >> y;
		v[i] = (P){x, y};
	}

	if (n == 1 || k == 1) cout << "Infinity" << endl;
	else {
		rep(i, n) {
			for (ll j = i + 1;j < n;j++) {
				double d, r;
				if (v[i].x == v[j].x) d = __DBL_MAX__;
				else d = (v[j].y - v[i].y) / (v[j].x - v[i].x);
				if (v[i].x == v[j].x) r = v[i].x;
				else r = v[j].y - d * v[j].x;

				ll cnt = 2;
				rep(ii, n) {
					if (ii == i || ii == j) continue;
					else {
						if (d == __DBL_MAX__) cnt += (v[ii].x == v[i].x ? 1 : 0);
						else if (v[ii].y == d * v[ii].x + r) cnt++;
					}
				}
				if (cnt >= k) {
					ans.insert(make_pair(d, r));
				}
			}
		}
		cout << ans.size() << endl;
	}
	return 0;
}