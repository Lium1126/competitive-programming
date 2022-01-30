#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)
#define HEAD (1 << 30)

using namespace std;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;

	ll head = 0;
	vector<ll> next(n + 1, 0);
	vector<ll> prev(n + 1, 0);
	next[0] = -1, prev[0] = HEAD;

	rep(i, n) {
		if (s[i] == 'L') {
			next[i + 1] = i;
			prev[i + 1] = prev[i];

			if (prev[i] == HEAD) head = i + 1;
			else next[prev[i]] = i + 1;

			prev[i] = i + 1;
		} else {
			next[i + 1] = next[i];
			prev[i + 1] = i;

			next[i] = i + 1;
		}
	}
/*
	rep(i, n + 1) {
		cout << i << ":" << next[i] << ' ' << prev[i] << endl;
	}
*/
	vector<ll> ans;
	ll i = head;
	while(i != -1) {
		ans.push_back(i);
		i = next[i];
	}

	rep(i, ans.size()) cout << ans[i] << (i != ans.size() - 1 ? ' ' : '\n');


	return 0;
}