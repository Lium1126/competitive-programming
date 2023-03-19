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
	ll n, q;
	cin >> n >> q;
	queue<ll> wait;
	set<ll> called;
	irep(i, n) wait.push(i);

	ll cmd, num;
	//cout << "----" << endl;
	rep (i, q) {
		cin >> cmd;
		if (cmd == 1) {
			called.insert(wait.front()); wait.pop();
		} else if (cmd == 2) {
			cin >> num;
			called.erase(num);
		} else {
			cout << *(called.begin()) << endl;
		}
	}

	return 0;
}