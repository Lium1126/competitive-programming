#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int main()
{
	ll n;
	cin >> n;

	n = (n >= 42 ? n + 1 : n);

	printf("AGC%03lld\n", n);

	return 0;
}