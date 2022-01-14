#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define reps(cnt, start, end, pitch) for (ll cnt = start;cnt <= end;cnt += pitch)

using namespace std;

int main() {
	ll n, x, y;
	cin >> n >> x >> y;

	bool flag = false;
	reps(i, 1, n, 1) {
		reps(j, i, n, 1) {
			reps(k, j, n, 1) {
				reps(l, k, n, 1) {
					if (i + j + k + l == x && i * j * k * l == y) flag = true;
				}
			}
		}
	}

	cout << (flag ? "Yes" : "No") << endl;

	return 0;
}