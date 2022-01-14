#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

typedef struct {
	ll x, y;
} P;

vector<P> p(55);

ll countInnerPoint(ll lx, ll rx, ll ly, ll ry, ll n) {
	ll cnt = 0;
	rep(i, n) if (lx <= p[i].x && p[i].x <= rx && ly <= p[i].y && p[i].y <= ry) cnt++;
	return cnt;
}

int main() {
	ll n, K;
	cin >> n >> K;

	rep(i, n) cin >> p[i].x >> p[i].y;

	ll ans = __LONG_LONG_MAX__;
	rep(i, n) {
		rep(j, n) {
			rep(k, n) {
				rep(l, n) {
					if (countInnerPoint(p[i].x, p[j].x, p[k].y, p[l].y, n) >= K) 
						ans = min(ans, (p[j].x - p[i].x) * (p[l].y - p[k].y));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}