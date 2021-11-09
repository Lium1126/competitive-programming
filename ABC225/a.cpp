#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	map<char, bool> m;
	string s;
	int cnt = 0;
	cin >> s;
	rep(i, s.length())
	{
		if (m[s[i]] == false)
		{
			m[s[i]] = true;
			cnt++;
		}
	}

	switch (cnt)
	{
	case 1:
		cout << 1 << endl;
		break;
	case 2:
		cout << 3 << endl;
		break;
	default:
		cout << 6 << endl;
		break;
	}

	return 0;
}