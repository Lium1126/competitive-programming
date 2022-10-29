#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <atcoder/all>
#include <cmath>

#define ll long long
#define rep(i, n)     for (ll i = 0;i < n;i++)
#define rrep(i, n)    for (ll i = n - 1;i >= 0;i--)
#define irep(i, n)    for (ll i = 1;i <= n;i++)
#define rirep(i, n)   for (ll i = n;i >= 1;i--)
#define srep(i, s, n) for (ll i = s;i <= n;i++)

using namespace std;
typedef pair<ll, ll> P;
typedef pair<P, P> PP;
typedef pair<PP, PP> Req;

vector<string> maps(9);

int isInside(P a, P b, P c, P t)
{
	ll ax = a.first, ay = a.second;
	ll bx = b.first, by = b.second;
	ll cx = c.first, cy = c.second;
	ll tx = t.first, ty = t.second;
    ll abXat, bcXbt, caXct;
 
    abXat = (bx-ax)*(ty-ay) - (by-ay)*(tx-ax);
    bcXbt = (cx-bx)*(ty-by) - (cy-by)*(tx-bx);
    caXct = (ax-cx)*(ty-cy) - (ay-cy)*(tx-cx);
  
    if(( abXat > 0 && bcXbt > 0 && caXct > 0) || ( abXat < 0 && bcXbt < 0 && caXct < 0))
    {
        return 1;
    }
    else if(abXat * bcXbt * caXct == 0)
    {
        return 1;
    }
 
    return 0;
}

ll dist(P a,P b) {
	return (abs(a.first - b.first) + abs(a.second - b.second));
}

int main() {
	rep(i, 9) {
		cin >> maps[i];
	}

	set<Req> req;
//	ll ans = 0;
	vector<P> porns;
	rep(i, 9) {
		rep(j, 9) {
			if (maps[i][j] == '#') porns.push_back(make_pair(j, i));
		}
	}

	if (porns.size() < 4) {
		cout << 0 << endl;
	} else {
		for (ll i = 0;i <= porns.size() - 4;i++) {
		for (ll j = i + 1;j <= porns.size() - 3;j++) {
		for (ll k = j + 1;k <= porns.size() - 2;k++) {
		for (ll l = k + 1;l <= porns.size() - 1;l++) {
			if (dist(porns[i], porns[j]) == dist(porns[k], porns[l]) && 
				dist(porns[i], porns[k]) == dist(porns[j], porns[l]) && 
				dist(porns[i], porns[j]) == dist(porns[i], porns[k]) && 
				!isInside(porns[i], porns[j], porns[k], porns[l]) && 
				!isInside(porns[j], porns[k], porns[l], porns[i]) && 
				!isInside(porns[k], porns[l], porns[i], porns[j]) && 
				!isInside(porns[l], porns[i], porns[j], porns[k])) {
//					ans++;
					vector<P> vec;
					vec.push_back(porns[i]);
					vec.push_back(porns[j]);
					vec.push_back(porns[k]);
					vec.push_back(porns[l]);
					sort(vec.begin(), vec.end());
					req.insert(make_pair(make_pair(vec[0], vec[1]), make_pair(vec[2], vec[3])));
					
					// cout << porns[i].first << ',' << porns[i].second << ' ' <<
					// porns[j].first << ',' << porns[j].second << ' ' <<
					// porns[k].first << ',' << porns[k].second << ' ' <<
					// porns[l].first << ',' << porns[l].second << endl;
				}
		}
		}
		}
		}
	}

	cout << req.size() << endl;

	return 0;
}