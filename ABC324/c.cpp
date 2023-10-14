#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <atcoder/all>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
using namespace atcoder;
typedef pair<string, ll> P;

#define SIZE (500001)

int snake(int k, int y, const string& str1, const string& str2)
{
    int x = y - k;

    while (x < str1.size() && y < str2.size() && str1[x] == str2[y]) {
        x++;
        y++;
    }

    return y;
}

int edit_distance_onp(const string& str1, const string& str2)
{
    // required: s1->size() <= s2->size()
    const string* const s1 = str1.size() > str2.size() ? &str2 : &str1;
    const string* const s2 = str1.size() > str2.size() ? &str1 : &str2;
    static int fp[SIZE];
    int x, y, k, p;
    int offset = s1->size() + 1;
    int delta = s2->size() - s1->size();
    for (int i = 0; i < SIZE; i++) fp[i] = -1;

    for (p = 0; fp[delta + offset] != s2->size(); p++) {
        for(k = -p; k < delta; k++)
            fp[k + offset] = snake(k, max(fp[k-1+offset] + 1, fp[k+1+offset]), *s1, *s2);
        for(k = delta + p; k > delta; k--)
            fp[k + offset] = snake(k, max(fp[k-1+offset] + 1, fp[k+1+offset]), *s1, *s2);
        fp[delta + offset] = snake(delta, max(fp[delta-1+offset] + 1, fp[delta+1+offset]), *s1, *s2);
    }

    return delta + (p - 1) * 2;
}

int main() {
	ll n;
	cin >> n;

	string t;
	cin >> t;

	string s;
	vector<ll> ans;

	irep(i, n) {
		cin >> s;
		int dist = edit_distance_onp(s, t);
		if (dist <= 1) ans.push_back(i);
		else if (dist == 2 && s.length() == t.length()) {
			ll cnt = 0;
			rep(j, t.length()) if (s[j] != t[j]) cnt++;
			if (cnt == 1) ans.push_back(i);
		}
	}

	cout << ans.size() << endl;
	for (ll out : ans) cout << out << ' ';
	cout << endl;

	return 0;
}
