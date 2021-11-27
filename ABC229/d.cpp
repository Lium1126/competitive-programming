#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

ll k, m = 0;
set<ll> dots;

ll solve(set<ll> d, ll cnt, ll now)
{
	//	cout << "cnt = " << cnt << " now = " << now << endl;
	if (cnt == k)
	{
		// 最大値を返す
		ll ret = 0;
		auto p = d.begin();
		p++;
		for (auto itr = d.begin(); p != d.end(); ++itr, ++p)
		{
			ret = max(ret, (*(p)-1 - *(itr)));
		}
		return ret;
	}
	if (now == m)
		return 0;

	auto itr = d.find(now);
	++itr;
	//	cout << "now = " << now << ": *(itr) = " << *(itr) << endl;
	set<ll> s = d;
	s.erase(now);
	return max(solve(d, cnt, *(itr)), solve(s, cnt + 1, *(itr)));
}

int main()
{
	string s;
	cin >> s;
	cin >> k;

	ll cnt = 0;
	rep(i, s.length())
	{
		if (s[i] == '.')
		{
			cnt++;
			dots.insert(i);
		}
		m = i;
	}

	if (cnt <= k)
	{
		cout << s.length();
	}
	else
	{
		// (cnt - k)個の.をどう配置する？
		cout << solve(dots, 0, *(dots.begin())) << endl;
	}

	return 0;
}