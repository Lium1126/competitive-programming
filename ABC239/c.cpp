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

typedef pair<ll, ll> P;

ll dist(P a, P b) {
	ll ab = a.first - b.first;
	ll cd = a.second - b.second;
	return ab * ab + cd * cd;
}

int main() {
	P a, b;
	cin >> a.first >> a.second >> b.first >> b.second;
	bool ans = false;
	P dif[8] = {
		P{-2, 1},
		P{-1, 2},
		P{1, 2},
		P{2, 1},		
		P{2, -1},
		P{1, -2},
		P{-1, -2},
		P{-2, -1}
	};

	for (P x : dif) {
		P c = P{a.first + x.first, a.second + x.second};
		if (dist(b, c) == 5) ans = true;
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}