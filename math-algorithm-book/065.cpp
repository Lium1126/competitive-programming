#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	ll h, w;
	cin >> h >> w;
	
	if (h == 1 || w == 1) cout << 1 << endl;
	else if (h % 2 == 0) cout << (h / 2) * w << endl;
	else if (w % 2 == 0) cout << h * (w / 2) << endl;
	else cout << (h / 2) * w + (w + 1) / 2 << endl;

	return 0;
}