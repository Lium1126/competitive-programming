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

#define ull unsigned long long
#define rep(i, n)     for (ull i = 0;i < n;i++)
#define rrep(i, n)    for (ull i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ull i = 1;i <= n;i++)
#define rirep(i, n)   for (ull i = n;i >= 1;i--)
#define srep(i, s, n) for (ull i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<ull, ull> P;

int main() {
	ull l, n1, n2, ans = 0;
	cin >> l >> n1 >> n2;

	vector<P> a(n1), b(n2);
	vector<P> t(n1);
	vector<ull> start, end;
	rep(i, n1) {
		cin >> a[i].first >> a[i].second;
		if (i == 0) {t[i].first = 1; t[i].second = a[i].second;}
		else {t[i].first = t[i-1].second + 1; t[i].second = t[i - 1].second + a[i].second;}
	}
	rep(i, n2) {
		cin >> b[i].first >> b[i].second;
		if (i == 0) {start.push_back(1); end.push_back(b[i].second);}
		else {start.push_back(end[i - 1] + 1); end.push_back(end[i - 1] + b[i].second);}
	}
	//rep(i, n1) cout << a[i].second << ": " << t[i].first << " ~ " << t[i].second << endl;
	/*
	rep(i, n2) cout << start[i] << ' ';
	cout << endl;
	rep(i, n2) cout << end[i] << ' ';
	cout << endl;
	*/

	rep(i, n1) {
		ull eidx = lower_bound(end.begin(), end.end(), t[i].second) - end.begin(); 
		auto itr = upper_bound(start.begin(), start.end(), t[i].first);
		ull sidx = (itr == start.begin()? itr - start.begin(): (itr - 1) - start.begin());
		//cout << t[i].first << "~" << t[i].second << ": lstart=" << start[sidx] << " lend=" << end[eidx] << endl;
		if (t[i].first == start[sidx] && t[i].second == end[eidx]) {
			ans += (a[i].first == b[sidx].first ? end[eidx] - start[sidx] + 1 : 0);
		}
		else if (t[i].first == start[sidx]) {
			ans += (a[i].first == b[sidx].first ? b[sidx].second : 0);
		}
		else if (t[i].second == end[eidx]) {
			ans += (a[i].first == b[eidx].first ? b[eidx].second : 0);
		}
	}

	cout << ans << endl;

	return 0;
}