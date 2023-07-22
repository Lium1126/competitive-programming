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
typedef pair<string, string> P;

int main() {
	ll n;
	cin >> n;

	string str;
	set<P> st;

	rep(i, n) {
		cin >> str;
		string cpy = str;
		reverse(str.begin(), str.end());
		P tmp = P{cpy, str};
		if (tmp.first > tmp.second) swap(tmp.first, tmp.second);
		st.insert(tmp);
	}

	cout << st.size() << endl;

	return 0;
}