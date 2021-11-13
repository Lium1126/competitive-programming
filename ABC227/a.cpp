#include <iostream>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n, k, a;
	cin >> n >> k >> a;
	rep(i, k - 1)
	{
		if (a == n)
			a = 1;
		else
			a++;
	}
	cout << a << endl;
	return 0;
}