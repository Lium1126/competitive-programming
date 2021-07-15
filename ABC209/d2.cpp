#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i,n) for (ll i = 0;i < n;i++)
#define MAX_V (100005)
#define INF (1<<30)

vector<ll> to[MAX_V];
ll mem[MAX_V][MAX_V] = {};

ll solve(ll s, ll t, ll cnt, ll now, ll from) {
    if (mem[s][t] != INF) return mem[s][t];
    if (t == now) return cnt;
    ll ret = INF;
    for (ll next : to[now]) {
        if (from != next) ret = min(ret, solve(s, t, cnt + 1, next, now));
    }
    return mem[s][t] = ret;
}

int main() {
    ll n, q;
    cin >> n >> q;
    ll a, b;

//    rep(i, MAX_V) rep(j, MAX_V) mem[i][j] = INF;
    memset(mem, INF, MAX_V * MAX_V);

    rep(i, n - 1) {
        cin >> a >> b;

        to[a].push_back(b);
        to[b].push_back(a);
    }

    for (ll i = 1;i <= n - 1;i++) {
        for (ll j = i + 1;j <= n;j++){
            solve(i, j, 0, i, -1);
        }
    }

    rep(i, q) {
        cin >> a >> b;
        if (mem[a][b] % 2 == 0) cout << "Town" << endl;
        else cout << "Road" << endl;
    }

    return 0;
}