#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define rep(i,n) for (int i = 0;i < n;i++)
#define MAX_V (100005)

vector<int> color(MAX_V, -1);
vector<int> to[MAX_V];

void solve(int now, int c) {
    color[now] = c;
    for (ll next : to[now]) {
        if (color[next] == -1) solve(next, (c + 1) % 2);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int a, b;

    rep(i, n - 1) {
        cin >> a >> b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    solve(1, 0);

    rep(i, q) {
        cin >> a >> b;
        if (color[a] == color[b]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }

    return 0;
}