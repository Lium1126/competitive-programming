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
	string s;
	cin >> s;

	map<char, int> m;
	for (char c : s) m[c]++;

	for (auto itr = m.begin();itr != m.end();itr++) {
		if((*itr).second == 1) {
			cout << (*itr).first << endl;
			return 0;
		}
	}

	cout << "-1" << endl;

	return 0;
}