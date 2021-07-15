#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int h, w, k;
int b_r[10] = {};
int b_c[10] = {};
char maze[10][10];

int main() {
    cin >> h >> w >> k;
    int b = 0;

    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '#') {
                b_r[i]++;
                b_c[j]++;
                b++;
            }
        }
    }

    /*
    for (int i = 0;i < h;i++) {
        cout << "b_r["  << i << "]:" << b_r[i] << endl;
    }
    for (int i = 0;i < w;i++) {
        cout << "b_c["  << i << "]:" << b_c[i] << endl;
    }
    */

   

    return(0);
}
