#include <bits/stdc++.h>
#define rep (i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

typedef pair<pair<int, int>, int> P;
typedef pair<int, int> Pair;

int h, w;
queue<P> que;
int m[1005][1005];
char maze[1005][1005];

void dfs(int x, int y, int cnt) {
    if (m[y][x] != -1) return;
    m[y][x] = cnt;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for (int i = -2;i <= 2;i++) {
        for (int j = -2;j <= 2;j++) {
            int ny = y + i, nx = x + j;
            if (maze[ny][nx] == '.' && nx >= 0 && nx < w && ny >= 0 && ny < h) {
                que.push((P){(Pair){(nx), (ny)}, cnt + 1});
            }
        }
    }

    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (maze[ny][nx] == '.' && nx >= 0 && nx < w && ny >= 0 && ny < h)
            dfs(x + dx[i], y + dy[i], cnt);
    }

    return;
}

int main () {
    int cx, cy;
    int dx, dy;

    cin >> h >> w;
    cin >> cy >> cx; cy--; cx--;
    cin >> dy >> dx; dy--; dx--;
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            cin >> maze[i][j];
            m[i][j] = -1;
        }
    }

    dfs(cx, cy, 0);
    while(!que.empty()) {
        /*
        cout << "---------------------------------" << endl;
        for (int i = 0;i < h;i++) {
            for (int j = 0;j < w;j++) {
                if (maze[i][j] == '#') cout << maze[i][j];
                else cout << m[i][j];
            }
            cout << endl;
        }
        */

        P p = que.front(); que.pop();
        dfs(p.first.first, p.first.second, p.second);
    }

    /*
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            if (maze[i][j] == '#') cout << maze[i][j];
            else cout << m[i][j];
        }
        cout << endl;
    }
    */

    cout << m[dy][dx] << endl;

    return(0);
}
