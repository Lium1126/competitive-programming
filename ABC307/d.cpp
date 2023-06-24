#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <stack>
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
typedef pair<bool, string> P;

int main() {
	stack<string> sstk;
	stack<bool> bstk;
	ll n;
	cin >> n;

	string s;
	cin >> s;

	rep(i, s.length()) {
		if (s[i] == '(') {
			sstk.push("(");
			bstk.push(true);
		} else if (s[i] == ')') {
			if (!bstk.empty()) {
				bool f = bstk.top();
				if (f) { sstk.pop(); bstk.pop(); }
				else { sstk.push(")"); bstk.push(false); }
			} else { sstk.push(")"); bstk.push(false); }
		} else {
			if (!sstk.empty()) {
				// string tmp = sstk.top(); sstk.pop(); //
				// tmp += s[i];
				// sstk.push(tmp);

				sstk.top().assign(sstk.top() + s[i]);
			} else {
				string tmp = "";
				tmp += s[i];
				sstk.push(tmp);
				bstk.push(false);
			}
		}
	}

	// string tmp = "";
	// bool flag = false;
	// rep(i, s.length()) {
	// 	if (s[i] != '(' && s[i] != ')') {
	// 		tmp += s[i];
	// 	}

	// 	if (s[i] == '(') {
	// 		sstk.push(tmp);
	// 		bstk.push(flag);
	// 		flag = true;
	// 		tmp = "(";
	// 	}

	// 	if (s[i] == ')') {
	// 		if (!bstk.empty()) {
	// 			bool f = bstk.top();
	// 			if (!tmp.empty()) tmp = "";
	// 			else if (f) {
	// 				 { sstk.pop(); bstk.pop(); }
	// 			}
	// 			else { sstk.push(tmp + ")"); tmp = ""; bstk.push(false); }
	// 		} 
	// 		else { sstk.push(")"); bstk.push(false); }
	// 	}
	// }


	vector<string> ans;
	while (!sstk.empty()) {
		string tmp = sstk.top(); sstk.pop();
		ans.push_back(tmp);
	}
	for (ll i = ans.size() - 1;i >= 0;i--) cout << ans[i];
	// if (!tmp.empty()) cout << tmp;
	cout << endl;

	return 0;
}