#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	string a, b;
	cin >> a >> b;

	cout << (((a == "#." && b == ".#") || (a == ".#" && b == "#.")) ? "No" : "Yes") << endl;
	return 0;
}