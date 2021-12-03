#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	string s, t = "";
	cin >> s;

	while (s.length() * 2 > t.length())
		t += "oxx";

	//	cout << t << endl;
	if (t.find(s) != string::npos)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}