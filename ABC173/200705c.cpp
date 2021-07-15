#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w, k;
int b_r[10] = {};
int b_c[10] = {};
char maze[10][10];

int solve(set<int> row, int r, set<int> col, int c, char m[10][10]) {
    int cnt = 0;
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            if (m[i][j] == '#') cnt++;
        }
    }
    if (cnt == k) return 1;
    if (cnt < k) return 0;

    char new_m[10][10];
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            if (row.find(i) != row.end() || col.find(j) != col.end()) {
                new_m[i][j] = '.';
            } else {
                new_m[i][j] = maze[i][j];
            }
        }
    }

    char new_m_r[10][10], new_m_c[10][10];
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            if (i == r + 1) {
                new_m_r[i][j] = '.';
            } else {
                new_m_r[i][j] = new_m[i][j];
            }
            if (j == c + 1) {
                new_m_c[i][j] = '.';
            } else {
                new_m_c[i][j] = new_m[i][j];
            }
        }
    }
    
    set<int> n_r = row; n_r.insert(r);
    set<int> n_c = col; n_c.insert(c);
    return solve(n_r, r + 1, col, c + 1, new_m_r) + solve(row, r + 1, n_c, c + 1, new_m_c) + solve(row, r + 1, col, c + 1, new_m);
}

int main() {
    cin >> h >> w >> k;

    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '#') {
                b_r[i]++;
                b_c[j]++;
            }
        }
    }

    set<int> row;
    set<int> col;
    cout << solve(row, 0, col, 0, maze) << endl;

    return(0);
}
