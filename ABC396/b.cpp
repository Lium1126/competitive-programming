#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
	ll q;
	cin >> q;

	stack<ll> stk;
	rep(i, 100) stk.push(0);

	ll cmd;
	while(q--) {
		cin >> cmd;
		switch(cmd) {
			case 1:
				ll x;
				cin >> x;
				stk.push(x);
				break;
			case 2:
				cout << stk.top() << endl;
				stk.pop();
		}
	}

	return 0;
}