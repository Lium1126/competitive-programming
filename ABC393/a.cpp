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
	string s1, s2;
	cin >> s1 >> s2;

	if (s1 == "fine" && s2 == "fine") {
		cout << 4 << endl;
	} else if (s1 == "fine" && s2 == "sick") {
		cout << 3 << endl;
	} else if (s1 == "sick" && s2 == "fine") {
		cout << 2 << endl;
	} else {
		cout << 1 << endl;
	}

	return 0;
}