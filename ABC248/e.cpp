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
	double x, y;
	ll ans = 0;
	rep(i, n) {
		cin >> x >> y;
		v[i] = (P){x, y};
	}

	if (k == 1) { cout << "Infinity" << endl; return 0; }
	
	vector<vector<bool>> mem(305, vector<bool>(305, true));
	rep(i, n) {
		for (ll j = i + 1;j < n;j++) {
			if (mem[i][j]) {
				P a = v[i], b = v[j];
				ll cnt = 2;
				vector<ll> idx; idx.push_back(i); idx.push_back(j);
				rep(ii, n) {
					if (ii == i || ii == j) continue;
					P p = v[ii];
					if ((b.x - a.x) * (p.y - a.y) == (b.y - a.y) * (p.x - a.x)) idx.push_back(ii);
				}

				if (idx.size() >= k) {
					ans++;
					for (ll x : idx) for (ll y : idx) mem[x][y] = mem[y][x] = false;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}