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

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	ll n, r, c;
	cin >> n >> r >> c;

	string s;
	cin >> s;

	P bonfire = {0, 0};
	P human = {r, c};
	set<P> smoke;
	smoke.insert(bonfire);

	for (char c : s) {
		switch (c) {
			case 'N':
				bonfire.first++;
				human.first++;
				break;
			case 'W':
				bonfire.second++;
				human.second++;
				break;
			case 'S':
				bonfire.first--;
				human.first--;
				break;
			case 'E':
				bonfire.second--;
				human.second--;
				break;
			default:
				break;
		}

		smoke.insert(bonfire);

		if (smoke.find(human) != smoke.end()) cout << 1;
		else cout << 0;
	}

	cout << endl;

	return 0;
}