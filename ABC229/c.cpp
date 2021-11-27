#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

typedef pair<ll, ll> P;

int main()
{
	ll n, w;
	cin >> n >> w;
	ll ans = 0;
	vector<P> a(n);

	rep(i, n)
			cin >>
		a[i].first >> a[i].second;

	/*
	sort(a.begin(), a.end(), [](P tmpa, P tmpb)
		 {
			 if (tmpa.first != tmpb.first)
				 return tmpa.first > tmpb.first;
			 else
				 return tmpa.second > tmpb.second;
		 });
*/

	sort(a.begin(), a.end());

	ll cnt = a.size() - 1;
	while (w > 0 && cnt >= 0)
	{
		ans += a[cnt].first * min(w, a[cnt].second);
		w -= min(w, a[cnt].second);
		cnt--;
	}

	cout << ans << endl;

	return 0;
}