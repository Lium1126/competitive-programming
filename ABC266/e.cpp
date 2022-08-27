#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
vector<double> mem(105, -1.0);
ll n;

double solve(ll now) {
	if (mem[now] != -1.0) return mem[now];
	double prev = solve(now - 1);
	ll sum = 0, cnt = 0;
	irep(i, 6) {
		if ((double)i >= prev) {
			sum += i, cnt++;
		}
	}
	return mem[now] = ((double)cnt / 6.0) * ((double)sum / (double)cnt) + ((double)(6 - cnt) / 6.0) * prev;
}

int main() {
	mem[1] = 3.5;
	cin >> n;
	printf("%.12lf\n", solve(n));

	return 0;
}
