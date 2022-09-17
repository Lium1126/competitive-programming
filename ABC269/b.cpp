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
#define INF 1000000000

using namespace std;

typedef pair<ll, ll> P;

int main() {
	vector<string> maps(10);
	rep(i, 10) cin >> maps[i];

	P ul = make_pair(INF, INF), lr = make_pair(0, 0);
	rep(i, 10) {
		rep(j, 10) {
			if (maps[i][j] == '#') {
				ul = min(ul, make_pair(j, i));
				lr = max(lr, make_pair(j, i));
			}
		}
	}

	cout << ul.second + 1 << ' ' << lr.second + 1 << endl;
	cout << ul.first + 1 << ' ' << lr.first + 1 << endl;

	return 0;
}