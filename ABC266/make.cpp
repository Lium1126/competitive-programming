#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;

int main() {
	cout << "200000" << endl;
	cout << "1 2" << endl;
	cout << "2 3" << endl;
	cout << "3 1" << endl;
	srep(i, 4, 200000) cout << i << ' ' << i - 1 << endl;
	cout << "200000" << endl;
	rep(i, 200000) cout << "1 2" << endl;
	return 0;
}