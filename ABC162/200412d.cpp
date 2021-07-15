#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;
using namespace std;

int main() {
    int n;
    string s;
    ll cnt = 0;
    int r[4001] = {};
    int g[4001] = {};
    int b[4001] = {};

    cin >> n;
    cin >> s;

    for (int i = 1;i <= n;i++) {
        r[i] = r[i - 1];
        g[i] = g[i - 1];
        b[i] = b[i - 1];
        if (s[i - 1] == 'R') r[i]++;
        if (s[i - 1] == 'G') g[i]++;
        if (s[i - 1] == 'B') b[i]++;
    }

    for (int i = 0;i < n;i++) {
        for (int j = 1;j < n;j++) {
            if (s[i] != s[i + j]) {
                int not_k = i + 2 * j;
                if (s[i] == 'R') {
                    if (s[i + j] == 'G') {
                        cnt += b[n] - b[i + j];
                        if (not_k < n && s[not_k] == 'B') cnt--;
                    } else if (s[i + j] == 'B') {
                        cnt += g[n] - g[i + j];
                        if (not_k < n && s[not_k] == 'G') cnt--;
                    }
                } else if(s[i] == 'G') {
                    if (s[i + j] == 'R') {
                        cnt += b[n] - b[i + j];
                        if (not_k < n && s[not_k] == 'B') cnt--;
                    } else if (s[i + j] == 'B') {
                        cnt += r[n] - r[i + j];
                        if (not_k < n && s[not_k] == 'R') cnt--;
                    }
                } else if(s[i] == 'B') {
                    if (s[i + j] == 'R') {
                        cnt += g[n] - g[i + j];
                        if (not_k < n && s[not_k] == 'G') cnt--;
                    } else if (s[i + j] == 'G') {
                        cnt += r[n] - r[i + j];            
                        if (not_k < n && s[not_k] == 'R') cnt--;
                    }
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
