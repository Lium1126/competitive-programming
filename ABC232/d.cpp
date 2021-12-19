#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <atcoder/all>

#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

typedef pair<ll, ll> Pair;
typedef pair<Pair, ll> P;

int main()
{
	ll h, w;
	cin >> h >> w;

	vector<string> maps(h);
	rep(i, h) cin >> maps[i];

	P start = P{Pair{0, 0}, 1};
	queue<P> que;
	que.push(start);
	ll ans = 0;
	while (!que.empty())
	{
		P now = que.front();
		que.pop();
		ans = max(ans, now.second);
		ll dx[2] = {1, 0};
		ll dy[2] = {0, 1};
		rep(i, 2)
		{
			ll nx = now.first.first + dx[i];
			ll ny = now.first.second + dy[i];
			if (0 <= nx && nx < w && 0 <= ny && ny < h && maps[ny][nx] != '#')
			{
				maps[ny][nx] = '#';
				que.push(P{Pair{nx, ny}, now.second + 1});
			}
		}
	}

	cout << ans << endl;

	return 0;
}