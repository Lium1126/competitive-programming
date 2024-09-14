#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ll, ll> P;

int main() {
	char ab, ac, bc;
	cin >> ab >> ac >> bc;

	if (ab == '<') {
		if (ac == '<') {
			if (bc == '<') cout << "B" << endl;
			if (bc == '>') cout << "C" << endl;
		} else {
			if (bc == '<') cout << "None" << endl;
			if (bc == '>') cout << "A" << endl;
		}
	}
	else {
		if (ac == '<') {
			if (bc == '<') cout << "A" << endl;
			if (bc == '>') cout << "None" << endl;
		} else {
			if (bc == '<') cout << "C" << endl;
			if (bc == '>') cout << "B" << endl;
		}
	}

	return 0;
}