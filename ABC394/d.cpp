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
	string s;
	cin >> s;

	stack<char> stk;
	for (char c : s) {
		if (c == '(' || c == '[' || c == '<') stk.push(c);
		else {
			if (stk.empty()) {
				cout << "No" << endl;
				return 0;
			}
			else if (c == ')' && stk.top() == '(') stk.pop();
			else if (c == ']' && stk.top() == '[') stk.pop();
			else if (c == '>' && stk.top() == '<') stk.pop();
			else {
				cout << "No" << endl;
				return 0;
			}
		}
	}

	if (!stk.empty()) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}