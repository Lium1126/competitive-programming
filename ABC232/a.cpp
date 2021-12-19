#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main()
{
	string s;
	cin >> s;

	cout << (s[0] - '0') * (s[2] - '0') << endl;

	return 0;
}