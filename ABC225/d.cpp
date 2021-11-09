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
	ll n, q;
	cin >> n >> q;
	ll c, x, y;

	rep(i, q)
	{
		cin >> c;
		switch (c)
		{
		case 1:
			// 電車yをxの後ろに連結する
			cin >> x >> y;
			break;
		case 2:
			// 電車xの後ろに連結しているyを分離
			cin >> x >> y;
			break;
		case 3:
			// 電車xが含まれる連結成分を先頭から順に表示
			cin >> x;
			break;
		}
	}

	return 0;
}