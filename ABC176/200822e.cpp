#include <bits/stdc++.h>
#define rep (i, n) for (int i = 0;i < n;i++)
using namespace std;
using ll = long long;

typedef pair<int, int> P;

int t[300005] = {};
int y[300005] = {};

int main () {
    int h, w, m;
    cin >> h >> w >> m;
    int hx, hy;
    set<P> s;
    for (int i = 0;i < m;i++) {
        cin >> hy >> hx; hy--; hx--;
        t[hy]++; y[hx]++;
        s.insert((P){hx, hy});
    }

    int ans = 0;
    int mt = 0, my = 0;
    vector<int> vx;
    vector<int> vy;

    for (int i = 0;i < w;i++) {
        if (mt < t[i]) {
            vx.clear();
            mt = t[i];
            vx.push_back(i);
        } else if (mt == t[i]) {
            vx.push_back(i);
        }
    }

    for (int i = 0;i < h;i++) {
        if (my < y[i]) {
            vy.clear();
            my = y[i];
            my = y[i];
            vy.push_back(i);
        } else if (my == y[i]) {
            vy.push_back(i);
        }
    }
    /*
    for (int i = 0;i < vx.size();i++) {
        cout << "vx["<< i<<"]:" << vx[i] << endl;
    }
    for (int i = 0;i < vy.size();i++) {
        cout << "vy["<< i<<"]:" << vy[i] << endl;
    }
    */
    for (int i = 0;i < vx.size();i++) {
        for (int j = 0;j < vy.size();j++) {
            if (s.find((P){vx[i], vy[j]}) != s.end()) ans = max(ans, mt + my - 1);
            else ans = max(ans, mt + my);
        }
    }
    

    cout << ans << endl;

    return(0);
}
