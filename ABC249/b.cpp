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
	string str;
	cin >> str;
	bool uf = false, lf = false;
	set<char> s;
	for (char c : str) {
		if ('a' <= c && c <= 'z') lf = true;
		if ('A' <= c && c <= 'Z') uf = true;
		s.insert(c);
	}
	cout << (lf && uf && s.size() == str.length() ? "Yes" : "No") << endl;
	return 0;
}