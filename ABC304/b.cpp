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
	ll n;
	cin >> n;

	if (n < 1000) cout << n << endl;
	else if (n < 10000) cout << (n / 10) * 10 << endl;
	else if (n < 100000) cout << (n / 100) * 100 << endl;
	else if (n < 1000000) cout << (n / 1000) * 1000 << endl;
	else if (n < 10000000) cout << (n / 10000) * 10000 << endl;
	else if (n < 100000000) cout << (n / 100000) * 100000 << endl;
	else if (n < 1000000000) cout << (n / 1000000) * 1000000 << endl;

	return 0;
}