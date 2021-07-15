#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0;i < n;i++)


typedef pair<ll, ll> Pair;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    set<Pair> visited;
    ll ans = LONG_LONG_MAX;
    queue<Pair> que;

    que.push((Pair){x, 0});
    while(!que.empty()) {
        ll now = que.front().first; 
        ll cnt = que.front().second; que.pop();
        ll neg = now - d;
        ll pos = now + d;

        if (visited.find((Pair){neg, cnt % 2}) == visited.end() && abs(neg) <= abs(x) && cnt < k) {
            visited.insert((Pair){neg, cnt % 2});
            que.push((Pair){neg, cnt + 1});
        }
        if (visited.find((Pair){pos, cnt % 2}) == visited.end() && abs(pos) <= abs(x) && cnt < k) {
            visited.insert((Pair){pos, cnt % 2});
            que.push((Pair){pos, cnt + 1});
        }
    }
    

    for(auto itr = visited.begin(); itr != visited.end(); ++itr) {
        if ((*itr).second != k % 2) ans = min(ans, abs((*itr).first));
//        cout << (*itr).first << " " << (*itr).second << endl;
    }

    cout << ans << endl;
}
