#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0 ;i < n;i++)
#define SIZE (1000000005)

short l[1000000005] = {};

int main() {
    int n;
    cin >> n;
    int input;
    int ans = 0;
    int m = 0;
    
    rep (i, n) {
        cin >> input;
        l[input]++;
        m = max(m, input);
    }

    for (int i = 1;i <= m;i++) {
        if (l[i] != 0) {
            int c = i;
            for (int j = i + 1;j <= m;j++) {
                if (l[j] != 0) {
                    int b = j;
                    for (int k = b + 1;k < b + c;k++) {
                            ans += l[i] * l[j] * l[k];
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
