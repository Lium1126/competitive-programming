#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	vector<bool> p(500, true);
	p[0] = false; p[1] = false;
	for (ll i = 2;i < 500;i++) {
		if (p[i]) for (ll j = i * 2;j < 500;j += i) p[j] = false;
	}

	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll cnt = 0;
	for (ll i = a;i <= b;i++) {
		bool flag = false;
		for (ll j = c;j <= d;j++) {
			if (p[i + j]) flag = true;
		}
		if (flag) cnt++;
	}

	if (cnt == b - a + 1) cout << "Aoki" << endl;
	else cout << "Takahashi" << endl;
	return 0;
}