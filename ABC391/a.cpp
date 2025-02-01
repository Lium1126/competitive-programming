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


// 北：N
// 東：E
// 西：W
// 南：S
// 北東：NE
// 北西：NW
// 南東：SE
// 南西：SW

int main() {
	map<string, string> m;
	m["N"] = "S";
	m["S"] = "N";
	m["E"] = "W";
	m["W"] = "E";
	m["NE"] = "SW";
	m["NW"] = "SE";
	m["SE"] = "NW";
	m["SW"] = "NE";

	string s;
	cin >> s;
	cout << m[s] << endl;

	return 0;
}