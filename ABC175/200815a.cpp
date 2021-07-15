#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0;i < n;i++)

int main() {
    string s;
    cin >> s;
    int ans = 0;
    rep (i, s.length()) {
        if (s[i] == 'R') {
            for (int j = i;j < s.length() && s[j] == 'R';j++) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;
}
