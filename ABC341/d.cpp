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
#define ull unsigned long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

ll n, m, k;

bool question(ll x) {
	return k <= (x / n) + (x / m) - (x / lcm(n, m)) * 2;
}

int main() {
	cin >> n >> m >> k;

	ll l = 0;
	ll r = __LONG_LONG_MAX__;
    while(r - l > 1){
        ll mid = l + (r - l) / 2;
        if(question(mid)) r = mid;
        else l = mid;
    }

	// cout << l << ' ' << r << endl;

	cout << r << endl;

	return 0;
}