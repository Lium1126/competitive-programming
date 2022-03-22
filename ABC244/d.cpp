#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0;i < n;i++)

using namespace std;

bool group(string s) {
	return s == "RGB" || s == "GBR" || s == "BRG";
}

int main() {
	string s = "", t = "";
	char c;
	rep(i, 3) {
		cin >> c;
		s += c;
	}
	rep(i, 3) {
		cin >> c;
		t += c;
	}

	cout << (group(s) == group(t) ? "Yes" : "No") << endl;
	
	return 0;
}