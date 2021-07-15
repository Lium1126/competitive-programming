#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_V (405)
#define INF (1 << 30)
#define ll long long
#define rep(i, n) for (long long i = 0;i < n;i++)

struct edge {
    ll to;
    ll cost;
};

typedef pair<ll, ll> P;  // first: 最短距離, second: 頂点番号

vector<edge> G[MAX_V], R[MAX_V]; // 隣接リスト表現

int n, m;

ll dijkstra(ll s, ll k) {
    ll d[MAX_V];
    fill(d, d + n + 1, INF);
    d[s] = 0;  // 始点sへの最短距離は0
    ll ret = 0;

    priority_queue<P, vector<P>, greater<P> > que;  // 距離が小さい順に取り出せるようgreater<P>を指定
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;  // 更新した頂点の中で距離が最小の頂点v
        if (d[v] < p.first) {
            continue;
        }
        for (auto e : G[v]) {  // 頂点vから出る辺eを走査
            if (d[e.to] > d[v] + e.cost && e.to <= k) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }

    for (ll t = 1;t <= n;t++) {
        if (d[t] != INF) {
            ret += d[t];
//            printf("s:%d t:%d k:%d = %d\n", s, t, k, d[t]);
        }
        else {
            ll a = INF;
            for (auto e : R[t]) if (e.to <= k || e.to == s) a = min(a, d[e.to] + e.cost);
            if (a != INF) ret += a;
//            printf("s:%d t:%d k:%d = %d\n", s, t, k, a);
        }
    }

    return ret;
}

int main() {
    cin >> n >> m;
    ll from, to, cost;
    ll ans = 0;
    rep(i, m) {
        cin >> from >> to >> cost;
        edge e; e.to = to; e.cost = cost;
        G[from].push_back(e);
        e.to = from;
        R[to].push_back(e);
    }

    for (ll s = 1;s <= n;s++) {
        for (ll k = 1;k <= n;k++) {
            ans += dijkstra(s, k);
        }
    }

    cout << ans << endl;

    return 0;
}
