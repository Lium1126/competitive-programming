#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

int main() {
	string s;
	vector<char> v;
	cin >> s;
	for (char x : s) v.push_back(x);
	sort(v.begin(), v.end());
	for (char x : v) cout << x;
	cout << endl;
	return 0;
}