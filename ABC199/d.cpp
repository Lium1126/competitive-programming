#include <iostream>
#include <vector>
using namespace std;

int n, m;

long long solve(vector< pair<vector<int>, char> > g, int now, int painted) {
    if (painted == n) return 1;

    vector< pair<vector<int>, char> > c;
    long long rec = 0;
    if (g[now].first.size() != 0) {

        for (int i = 0;i < g[now].first.size();i++) {
            int to = g[now].first[i];
            if (g[to].second == 'W') {
                if (g[now].second == 'R') {
                    c = g;
                    c[to].second = 'G';
                    rec += solve(c, to, painted + 1);
                    c = g;
                    c[to].second = 'B';
                    rec += solve(c, to, painted + 1);
                } else if (g[now].second == 'G') {
                    c = g;
                    c[to].second = 'R';
                    rec += solve(c, to, painted + 1);
                    c = g;
                    c[to].second = 'B';
                    rec += solve(c, to, painted + 1);
                } else if (g[now].second == 'B') {
                    c = g;
                    c[to].second = 'R';
                    rec += solve(c, to, painted + 1);
                    c = g;
                    c[to].second = 'G';
                    rec += solve(c, to, painted + 1);
                }
            }
        }

    } else {
        for (int i = 0;i < n;i++) {
            if(g[i].second == 'W') {
                c = g;
                c[i].second = 'R';
                rec += solve(c, i, painted + 1);
                c = g;
                c[i].second = 'G';
                rec += solve(c, i, painted + 1);
                c = g;
                c[i].second = 'B';
                rec += solve(c, i, painted + 1);
            }
        }
    }
    
    return rec;
}

int main() {
    int from, to;

    long long ans = 0;

    cin >> n >> m;

    vector< pair<vector<int>, char> > g;
    vector<int> empty;
    pair<vector<int> , char> p;
    p.first = empty; p.second = 'W';
    for (int i = 0;i <= n;i++) {
        g.push_back(p);
    }

    for (int i = 0;i < m;i++) {
        cin >> from >> to;
        g[from].first.push_back(to);
        g[to].first.push_back(from);
    }

/*
    for (int i = 1;i <= n;i++) {
        cout << i << ":";
        for (int j = 0;j < g[i].size();j++) {
            if (j != g[i].size() - 1) cout << g[i][j] << ' ';
            else cout << g[i][j] << endl;
        }
    }
*/
    g[1].second = 'R';
    ans += solve(g, 1, 1);
    g[1].second = 'G';
    ans += solve(g, 1, 1);
    g[1].second = 'B';
    ans += solve(g, 1, 1);

    cout << ans << endl;

    return(0);
}
